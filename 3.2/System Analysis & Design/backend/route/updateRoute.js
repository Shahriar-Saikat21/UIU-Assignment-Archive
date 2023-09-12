//external imports
const express = require('express');

//internal imports
const updateController = require('../controller/updateController');
const authentication = require('../middleware/authentication');// authentication middleware

const updateRoute = express.Router();

//show update page
updateRoute.get('/updateMemory', authentication,updateController.updatePage);

//show data for update page
updateRoute.get('/updateMemoryData', authentication,updateController.updateData);

//update memory
updateRoute.put('/updateMemory', authentication,updateController.updateMemory);

module.exports = updateRoute;