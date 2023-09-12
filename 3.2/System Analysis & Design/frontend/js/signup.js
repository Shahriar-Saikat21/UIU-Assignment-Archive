const form = document.querySelector('.form');
let userP = document.querySelector('.userP');
let emailP = document.querySelector('.emailP');
let passP = document.querySelector('.passwordP');

form.addEventListener('submit', async (e) => {
    e.preventDefault();
    
    const data = new FormData(form);
    const formObject = Object.fromEntries(data);
    const jsonData = JSON.stringify(formObject);

    fetch('/signupUser', {
        method: 'POST',
        headers: {
            'content-type': 'application/json'
        },
        body : jsonData
    })
    .then(res => res.json())
    .then(data => {
        if(data.success===true){
            alert(data.message);
            window.location.href = "/";
        }else{
            userP.innerHTML = "";
            emailP.innerHTML = "";
            passP.innerHTML = "";
            if(data.err.userName){
                userP.innerHTML = data.err.userName.msg;               
            }else if(data.err.email){
                emailP.innerHTML = data.err.email.msg;
            }else if(data.err.password){
                passP.innerHTML = data.err.password.msg;
            }
        }
    })
    .catch(err => console.log(err.message));
});