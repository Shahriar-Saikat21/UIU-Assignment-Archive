let username = document.querySelector('.hTag');
let id = document.querySelector('.pTag');


function detail(){
    fetch('/showUserDetail')
    .then(res => res.json())
    .then(data => {
        if(data.success){
            username.innerHTML = `Welcome ${data.user.userName}`;
            id.innerHTML = data.user.id;
        }else{
            username.innerHTML = data.message;
            id.innerHTML = "";
        }
    })
    .catch(err => console.log(err.meesage));
};

detail();