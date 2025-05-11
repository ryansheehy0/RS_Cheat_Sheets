<!--
 * This file is part of RS Cheat Sheets.
 *
 * RS Cheat Sheets is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RS Cheat Sheets is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RS Cheat Sheets. If not, see <https://www.gnu.org/licenses/>.
 */
-->

[Home](../README.md)

# Cross Site Request Forgery(CSRF)

Steps for CSRFs:
1. Victim logs into Site A and gets a session cookie.
1. While the user is still logged into Site A, they visit the attacker's websites(Site B).
1. Site B sends a malicious request to Site A.
1. The browser will automatically add Site A's session cookie to the malicious request and thus Site A accepts the malicious request.

This is especially bad if Site B can guarantee some users from Site A, like, for example, posting Site B's link in the comment section on Site A.

<!-- TOC -->

- [Things required for CSRFs](#things-required-for-csrfs)
- [Why form over fetch](#why-form-over-fetch)
- [Sending JSON through form](#sending-json-through-form)
- [Downsides to SameSite strict cookies and localstorage for sessions](#downsides-to-samesite-strict-cookies-and-localstorage-for-sessions)
- [CSRF tokens](#csrf-tokens)

<!-- /TOC -->

## [Things required for CSRFs](#cross-site-request-forgerycsrf)
1. **Malicious action**: An action that the attacker would want to perform as another user.
1. **Cookie based session handling**: The server relies solely on the cookie session to identify the user who made the request. If the cookie has SameSite set to strict then CSRFs aren't possible.
1. **Predictable arguments**: The request doesn't contain any arguments that an attacker doesn't know or can't guess.

Ex:
```
POST /email/change HTTP/1.1
Host: vulnerable-website.com
Content-Type: application/x-www-form-urlencoded
Content-Length: 30
Cookie: session=yvthwsztyeQkAPzeQ5gHgTvlyxHfsAfE

email=wiener@normal-user.com
```
- This meats the 2 requirements.

Often times the malicious request is sent to Site A through a hidden html form.
```html
<html>
    <body>
        <form action="https://vulnerable-website.com/email/change" method="POST">
            <input type="hidden" name="email" value="pwned@evil-user.net" />
						<button type="submit">CSRF attack</button>
        </form>
        <script>
						// If you want to automatically submit the form on page load.
            document.forms[0].submit()
        </script>
    </body>
</html>
```

## [Why form over fetch](#cross-site-request-forgerycsrf)
Fetch requires CORS(cross origin resource sharing) which doesn't allow cross domain cookies from being automatically added to the request.

Forms use `Sec-Fetch-Mode: navigate` header which does automatically add the headers.

I think AJAX does work though.

## [Sending JSON through form](#cross-site-request-forgerycsrf)
Form sends data through key value pairs not json.

Ex: `data=value`

If you want to convert this to valid json you could set data to `{"key": "value", "junk": "` and value to `test"}`. This would result in the output being `{"key": "value", "junk": "=test"}` which would be valid json.
- This only works if the server will just ignore the junk key.

Sometimes the server requires the `Content-Type: application/json` header to be set. This can only be done through AJAX and the server has to allow you to do so through CORS.

The server has to set these headers to allow you to set the Content-Type header:
```
Access-Control-Allow-Origin: website
Access-Control-Allow-Headers: Content-Type
```

## [Downsides to SameSite strict cookies and localstorage for sessions](#cross-site-request-forgerycsrf)
localstorage:
- Divided between HTTP and HTTPS
- Divided between subdomains

sessionstorage:
- Divided between HTTP and HTTPS
- Divided between subdomains
- Divided between each tab and browser window

SameSite strict cookies:
- Not divided between HTTP and HTTPS
- Divided between subdomains

This would be undesirable if, for example, you want the user to continue their sign in from one subdomain to another. Like docs.google.com and drive.google.com

## [CSRF tokens](#cross-site-request-forgerycsrf)
1. Server sends a random value(CSRF token) to the client along with there cookie session.
1. The client stores this CSRF token in a local variable.
1. Whenever the client sends a request back to the serve that CSRF token has to be sent as well
1. The server checks if the session's CSRF token matches the CSRF token sent along with the request. If it does then it allows the request, if not it doesn't allow.

Since Site B has no way of knowing this random value(CSRF token), they cannot perform a CSRF attack.