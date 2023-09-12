//internal imports
const Memory = require('../model/memoryModel.js'); //memory model

const deleteController = async(req, res) => {
    const value = req.query.id;
    try {
        await Memory.deleteOne({_id:value});
        res.status(500).json({message: "Memory Deleted Successfully",success:true});
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

module.exports = deleteController;