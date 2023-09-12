//external imports
const express = require('express');

//internal imports
const signupControl = require('../controller/signupController.js');
const {addUserValidators,addUserValidationHandler} = require('../middleware/signupValidation.js'); //signup validation middleware


const signupRoute = express.Router();


//signup page
signupRoute.get('/signup', signupControl.signupPage);

//signup user
signupRoute.post('/signupUser',addUserValidators,addUserValidationHandler, signupControl.signupUser);

module.exports = signupRoute;