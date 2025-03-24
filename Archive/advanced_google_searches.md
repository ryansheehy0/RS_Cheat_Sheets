[Home](../README.md)

# Advanced Google Searches

Useful features for more advanced searches in google search engine.
- You can use ()s to group together certain operations

<!-- TOC -->

- [Matching Operators](#matching-operators)
- [Date Operators](#date-operators)
- [Source Operators](#source-operators)
- [Boolean operators](#boolean-operators)
- [INURL/Title/Text/Anchor Operators](#inurltitletextanchor-operators)
- [Utility Operators](#utility-operators)
- [Links](#links)

<!-- /TOC -->

## [Matching Operators](#advanced-google-searches)

| Operator              | Description                                                                                                 |
|-----------------------|-------------------------------------------------------------------------------------------------------------|
| ""                    | Matches exactly what's in the quotes. Overrides spell correction.                                           |
| -word                 | Excludes that word from the search.                                                                         |
| *                     | Wildcard which can be used to replace words or phrases. Useful if you can't remember some part of a phrase. |
| word1 AROUND(#) word2 | Find pages which have word1 within # of words from word2.                                                   |

- The wildcard(*) is useful when you have a local directory that you want to exclude in your search.

## [Date Operators](#advanced-google-searches)

| Operator | Description                   |
|----------|-------------------------------|
| BEFORE:  | Only results before that data |
| AFTER:   | Only results after that date  |

- YYYY-MM-DD is the format. Ex: `after:2021-01-01`, `after:2021`
- You can also specify a range with `...`. Ex: `2016...2018`
  - These don't have to be used for dates. Ex: `"top 7...10 fact"`

## [Source Operators](#advanced-google-searches)

| Operator         | Description                                                 |
|------------------|-------------------------------------------------------------|
| site:name.net    | Filters by that domain name.                                |
| filetype:pdf     | Filters by filetype. In this case pdf.                      |
| loc:SF           | Changed location fo the search                              |
| blogurl:name.net | Filters by blogs of that site                               |
| cache:name.net   | If the site is down it gets the cached version of the site. |

## [Boolean operators](#advanced-google-searches)

| Operator | Description                                                            |
|----------|------------------------------------------------------------------------|
| OR       | Searches for something or something else. This increases your results. |
| AND | |

## [IN(URL/Title/Text/Anchor) Operators](#advanced-google-searches)

| Operator  | Description                         |
|-----------|-------------------------------------|
| inurl:    | Searches in the url                 |
| intitle:  | Searches in the title               |
| intext:   | Searches in the text of the website |
| inalchor: | Invisible links to other webpages.  |

- `allin` can be used instead of `in` and it means it only contains the results with all of the following terms.
  - Ex: `allintitle:this is an example` only results with `this is an example` in the title

## [Utility Operators](#advanced-google-searches)


| Operator         | Description                                  |
|------------------|----------------------------------------------|
| define:          | Gives a definition of word                   |
| related:name.net | Returns other sites relative to that domain. |
| ip               | gives your ip address                        |
| $ in EUR         | Convert between units                        |
| weather:location | Weather of that location                     |
| map:location     | Map of the location                          |
| stock:amzn       | Pulls up the stock from the ticker name      |
| timer            | Pulls up timer                               |
| calc             | Pulls up calculator                          |
| tip calculator | |

## [Links](#advanced-google-searches)
- https://images.google.com/
  - Reverse image search -> Click the colored camera
- https://scholar.google.com/
- https://patents.google.com/