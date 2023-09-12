//external imports
const mongoose = require('mongoose');

const memorySchema = mongoose.Schema({
    title : {
        type : String,
        required : true,
    },
    story:{
        type : String,
        required : true,
    },
    image : {
        data: Buffer,
        contentType : String
    },
    user : {
        type : mongoose.Types.ObjectId,
        ref : 'users',
    },
    date :{
        type : Date,
        default : Date.now
    }
});

const memoryModel = mongoose.model('memories',memorySchema);

module.exports = memoryModel;