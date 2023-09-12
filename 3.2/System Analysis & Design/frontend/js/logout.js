const logoutbtn = document.querySelector('.aTag');

logoutbtn.addEventListener('click', (e) => {
    e.preventDefault();
    sessionStorage.clear();
    fetch('/logout',)
    .then(res => res.json())
    .then(data => {
        if(data.success){
            alert(data.message);
            window.location.href = "/";
        }else{
            alert(data.message);
        }
    })
    .catch(err => console.log(err.message));
});