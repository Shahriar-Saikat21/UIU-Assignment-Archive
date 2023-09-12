const section = document.querySelector('.section');

sessionStorage.clear();

function showMemory(){
    fetch('/showMemory')
    .then(res => res.json())
    .then(data => {
        section.innerHTML = "";
        if(data.success){           
            if(data.memories.length > 0){
                data.memories.forEach(i => {                
                    const markup = `<div class="card my-2" style="width: 30rem;" id=${i._id}>
                    <img src="data:${i.image.contentType};base64,${arrayBufferToBase64(i.image.data.data)}" class="img-thumbnail" style="width:100%; height:200px; object-fit: cover" alt="...">
                    <div class="card-body">
                        <h2 class="card-text">${i.title}</h2>
                        <p class="card-text">${i.date}</p>
                    </div>
                </div>`;
                section.insertAdjacentHTML('beforeend',markup);
                
                showMemoryBtn();
                
                });
            
            }else{
                section.insertAdjacentHTML('beforeend',`<h1>No Memory Found</h1>`);
            }
        }else{
            section.innerHTML = "";
            section.insertAdjacentHTML('beforeend',`<h1>${data.message}</h1>`);
        }
    })
    .catch(err => console.log(err.meesage));
};


function arrayBufferToBase64(buffer) {
    let binary = '';
    const bytes = new Uint8Array(buffer);
    const len = bytes.byteLength;
    for (let i = 0; i < len; i++) {
      binary += String.fromCharCode(bytes[i]);
    }
    return window.btoa(binary);
}

showMemory();

function showMemoryBtn(){
    const btns = document.querySelectorAll('.card');
    for(let i of btns){
        i.addEventListener('click', function(e){
            e.preventDefault();
            sessionStorage.setItem('memoryId',i.id);
            window.location.href = "/myStory";
        });
    }
};




