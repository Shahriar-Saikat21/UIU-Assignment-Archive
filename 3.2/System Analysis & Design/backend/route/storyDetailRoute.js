//external imports
const express = require('express');

//internal imports
const authentication = require('../middleware/authentication.js'); //authentication middleware
const storyDetailController = require('../controller/storyDetailController.js'); //story detail controller

const storyDetailRoute = express.Router();

//show memory detail page
storyDetailRoute.get('/myStory', authentication,storyDetailController.storyDetail);

//show memory detail content on the page
storyDetailRoute.get('/storyDetail', authentication,storyDetailController.storyDetailContent);


module.exports = storyDetailRoute;