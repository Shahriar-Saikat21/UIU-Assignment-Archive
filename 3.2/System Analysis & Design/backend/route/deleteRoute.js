//external imports
const express = require('express');

//internal imports
const authentication = require('../middleware/authentication.js'); //authentication middleware
const deleteController = require('../controller/deleteController.js'); //delete controller

const deleteRoute = express.Router();

//delete memory
deleteRoute.get('/deleteStory', authentication,deleteController);

module.exports = deleteRoute;