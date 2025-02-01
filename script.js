let inputBox = document.getElementById('input-box');
let disp = document.getElementById('list-container');

function addTask() {
    if (inputBox.value === '') {
        alert('Nothing To Add');
    }
    else {
        let li = document.createElement("li");
        li.innerHTML = inputBox.value;
        disp.appendChild(li);

        let span = document.createElement("span");
        span.innerHTML = "\u00d7";
        li.append(span)
    }
    //after ifelse complete..element added...now clear input box
    inputBox.value = "";

    //save changes in cache
    saveData()
}

//When enter pressed..also call the addTask
function AddOnEnter() {
    let btn1 = document.getElementById('btn1');
    document.addEventListener('keydown', (e) => {
        // console.log(e, e.key, e.keyCode)
        if (e.key === "Enter" && document.activeElement === inputBox) {
            addTask();
        }
    });
}
AddOnEnter()


//Handling toggling removing and all
disp.addEventListener('click', (e) => {
    //If we click on LI it should add the checked classname
    // and if "checked" classname already there..it will be removed
    //<li class="checked">Task 1</li>
    if (e.target.tagName === "LI") {
        e.target.classList.toggle("checked");
        saveData()
    }
    else if (e.target.tagName === "SPAN") {
        e.target.parentElement.remove();
        saveData()
    }

    //if spanned ele clicked.that means the cross..it will remove the parent ele LI ...LI>span

}, false);

//until this..if we refresh ..our data is gone..thus save it in cache of browser
//call this save data function whenever we make any changes / remove task / mark it cheked..thus add it in addTask func and addeve

function saveData() {
    localStorage.setItem("data", disp.innerHTML)
}

//now display saved data
function showTask() {
    disp.innerHTML = localStorage.getItem("data");
}
showTask() 
