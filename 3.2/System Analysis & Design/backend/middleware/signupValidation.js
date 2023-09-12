const {check,validationResult} = require('express-validator');
const createError = require('http-errors');
const User = require('../model/userModel'); //user model

const addUserValidators = [
    check("userName")
      .isLength({ min: 3 }).withMessage("Minimum length 3 is required")
      .trim(),
    check("email")
      .isEmail().withMessage("Invalid email address")
      .trim()
      .custom(async (value) => { //Custom validator
        try {
          const user = await User.findOne({ email: value });
          if (user) {
            throw createError("Email is  already used!");
          }
        } catch (err) {
          throw createError(err.message);
        }
      }),
    check("password")
      .isStrongPassword()
      .withMessage(
        "Password must be at least 8 characters long & should contain at least 1 lowercase, 1 uppercase, 1 number & 1 symbol"
      ),
];
  
const addUserValidationHandler = function (req, res, next) {
    const errors = validationResult(req);
    const mappedErrors = errors.mapped();
    if (Object.keys(mappedErrors).length === 0) {
        next();
    } else {
        // response the errors
        res.status(500).json({err: mappedErrors});
    }
};

module.exports = {
    addUserValidators,
    addUserValidationHandler
}