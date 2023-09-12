//external import
const express = require('express');


//internal import
const authentication = require('../middleware/authentication.js'); //authentication middleware
const homeControl = require('../controller/homeController.js'); //home controller

const homeRoute = express.Router();

//user home page
homeRoute.get('/home',authentication,homeControl.home);

// show user detail in home page
homeRoute.get('/showUserDetail',authentication,homeControl.userDetail);

//show memory list in user home page
homeRoute.get('/showMemory', authentication,homeControl.showMemory);

module.exports = homeRoute;