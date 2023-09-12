//external imports
const express = require('express');

//internal imports
const authentication = require('../middleware/authentication.js'); //authentication middleware
const addMemoryControll = require('../controller/addMemoryController.js'); //add memory controller
const upload = require('../middleware/multerUpload.js'); //upload middleware

const addMemoryRoute = express.Router();

//addMemory page
addMemoryRoute.get('/addMemory',authentication, addMemoryControll.addMemoryPage);

//Post memory
addMemoryRoute.post('/postMemory',authentication,upload.single('image'), addMemoryControll.addMemory);

module.exports = addMemoryRoute;