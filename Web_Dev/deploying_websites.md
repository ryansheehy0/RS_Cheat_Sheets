[Home](../README.md)

# Deploying Websites

<!-- TOC -->

- [Github Pages](#github-pages)
	- [Github Pages Adding Domain Name](#github-pages-adding-domain-name)
- [Heroku](#heroku)
	- [Website](#website)
	- [Terminal](#terminal)
	- [Using keys](#using-keys)
	- [MySQL](#mysql)
	- [Heroku Adding Domain Name](#heroku-adding-domain-name)
- [Netlify](#netlify)
	- [Netlify Adding Domain Name](#netlify-adding-domain-name)
- [Vercel](#vercel)
	- [Vercel adding domains](#vercel-adding-domains)
- [MongoDB Atlas](#mongodb-atlas)
	- [Making a new project](#making-a-new-project)
	- [Deleting a new project](#deleting-a-new-project)
- [Domain Names](#domain-names)

<!-- /TOC -->

## [Github Pages](#deploying-websites)
1. Push your code to git. Have your deployable code in the "docs" folder
  - Make sure it is all correct because it maybe hard to change the website once it is deployed
1. Go to "Settings" tab and click "Pages" on the left side
1. Change "none" to your branch you want ot deploy from
1. Change "/(root)" to "/docs"
1. Click "Save" and wait. It may take a while
  - Any new pushes to that branch should be automatically deployed
  - If any new changes are taking a very long time to deploy then you need to create a new repo with your code and deploy from that.

### [Github Pages Adding Domain Name](#deploying-websites)
1. On github go to user -> Settings -> Pages
1. Click Add a domain
1. Put your domain name in and follow the direction(Adding A TXT DNS record).
1. Click Add domain and wait for it to verify
1. Go to your github pages repo -> Settings -> Pages
1. Add you Custom domain and click save

On Porkbun
1. Login
1. Account -> Domain Management
1. Click the arrow down in the red box on the right of you domain name you want to use
1. Under DNS RECORDS click Edit
1. Remove the 2 default DNS records of type ALIAS and CNAME*
1. Add TYPE CNAME, Host www, and ANSWER (github username).github.io.
1. Add 4 TYPE A DNSs. Leave the Host blank and put these 4 ip addresses
  - 185.199.108.153
  - 185.199.109.153
  - 185.199.110.153
  - 185.199.111.153
  - These may change in the future. So double check on this [website](https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site).

You have to wait around 30 mins.
- After around 30 min on your github pages repo click Check Again under your Custom domain

## [Heroku](#deploying-websites)

### [Website](#deploying-websites)
1. Login or create Heroku account at `https://id.heroku.com/login`
1. Click on top right "New" and click "Create new app"
1. Give an app name of `{github username}-{github repo name}`
  - Make sure to replace any spaces or underscores with dashes
  - You can name it whatever you want, but this is the recommended naming convention
1. Click create app
1. Go to "Deploy" tab and set your deployment method to github and connect your github repo
1. Got to "Settings" tab and set your buildpack to what your app is using.

### [Terminal](#deploying-websites)
1. Make sure to have the Heroku CLI installed at this link https://devcenter.heroku.com/articles/heroku-cli
  - On Linux: `curl https://cli-assets.heroku.com/install-ubuntu.sh | sh`
1. Run `heroku login` in the terminal
  - A website should popup and make sure to login there
1. Make sure your code is pushed to your git branch
1. Run `heroku git:remote -a my-app`, but replace my-app with the app name you gave.
  - This should create a new heroku location for git
1. Run `git subtree push --prefix my-subdirectory heroku master`, but replace my-subdirectory with your root directory and replace master with your branch you want to deploy from.
  - This will make Heroku use my-subdirectory as the root directory

### [Using keys](#deploying-websites)
- On the Heroku website go to Settings and click Show Config Vars
- In nodeJS use the package dotenv and use the Keys that are in your Config Vars

### [MySQL](#deploying-websites)
1. Go to Resources
1. Search for JawsDB MySQL
1. JAWSDB_URL should be automatically added in your config vars

### [Heroku Adding Domain Name](#deploying-websites)
1. On heroku website go to Settings
1. Click Add domain
1. Paste your domain name
1. Copy the DNS target link

On Porkbun
1. Login
1. Account -> Domain Management
1. Click the arrow down in the red box on the right of you domain name you want to use
1. Under DNS RECORDS click Edit
1. Remove the 2 default DNS records of type ALIAS and CNAME*
1. Set type to ALIAS, leave Host blank, and past your heroku DNS target link under Answer. Then Click Add
1. Set type to CNAME, under Host put *, and past your heroku DNS target link under Answer. Then Click Add

## [Netlify](#deploying-websites)
1. `npm run build` to get a dist folder
2. Go to [netlify](https://app.netlify.com/)
3. Drag and drop dist folder into sites in netlify

### [Netlify Adding Domain Name](#deploying-websites)
1. Domain management
1. Add domain name
1. Type your registered domain name -> Add domain (There should be something saying it was already registered) -> Add domain again
1. On your domain name click options -> Set up Netlify DNS
1. Verify -> Add domain -> Continue -> You should get ~4 domain name servers. Make sure to copy these.

On your register website(Not netlify) paste those ~4 domain name servers in NS.

## [Vercel](#deploying-websites)
Vercel doesn't allow you to make monetary transactions on the free tear.

### [Vercel adding domains](#deploying-websites)
1. Top left ryansheehy0's projects
2. Click the 3 dots to the left of your project
3. Manage domains
4. Add A record to DNS on porkbun
5. Add CNAME record to DNS on porkbun
When adding domain names add the A records and the C

## [MongoDB Atlas](#deploying-websites)
[MongoDB Atlas](https://www.mongodb.com/atlas)

### [Making a new project](#deploying-websites)
1. Top left project dropdown -> + New Project
1. Name your project
1. Create Project
1. Create a deployment
1. For this user there should be an auto-generated username and password. **Make sure to save the auto-generated password.**
1. Create User
1. Finish and Close
1. Left side -> Under the green security header -> Network Access
1. Edit button
1. Allow access from anywhere
1. Confirm
1. Left side -> Overview
1. Green connect button
1. Drivers
1. Copy the connection string which starts with `mongodb+srv://`
1. Replace `<password>` with the password from your user you saved.
1. You can now connect to the db with this link

### [Deleting a new project](#deploying-websites)
1. Left side -> Under the green Deployment header -> Database
1. Click on cluster name link in blue
1. Right side 3 dot buttons
1. Terminate
1. Wait for cluster to shut down and be removed
1. Top left project dropdown -> View All Projects
1. Delete your project with the trash button

## [Domain Names](#deploying-websites)
- [Porkbun](https://porkbun.com/)
  - Under your domain name. Small red NS and paste in.