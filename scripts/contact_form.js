document.getElementsByClassName("slider")[0].style.display = "block";
    const name = document.getElementById('name');
    const email = document.getElementById("email");
    const comments = document.getElementById("comments");
    const form = document.getElementById("contactForm");
    var error = document.getElementById("error");
    var info = document.getElementById("info");

    let form_errors = [];

    const commentAllowedPattern = /^[A-Za-z .?]+$/;
    const nameAllowedPattern = /^[A-Za-z -]+$/;

    name.addEventListener("input", (event) => {
    error.classList.remove('fade-out');

    if (!nameAllowedPattern.test(name.value)) {
        error.textContent = "Error: Illegal Character!";
        
        let errors = "Name Error: Bad Character " + name.value;
        form_errors.push(errors);
        name.classList.add('bad_input')
    } else {
        error.textContent = "No Errors";
    }

    setTimeout(() => {
        name.classList.remove('bad_input');
    }, 100);

    setTimeout(() => {
        error.classList.add('fade-out');
    }, 1000);
    });

    email.addEventListener("input", (event) => {
    email.classList.remove('fade-out');

    if(email.validity.typeMismatch) {
        error.textContent = "Error: Expecting an email!";
        let errors = "Email Error: Bad Input ";
        form_errors.push(errors);
    } else {
        error.textContent = "No Errors";
    }

    setTimeout(() => {
        error.classList.add('fade-out');
    }, 1000);
    });

    comments.addEventListener("input", (event) => {
    var cnt = comments.value.length;
    error.classList.remove('fade-out');

    const lastChar = event.data || comments.value.slice(-1);

    if (!commentAllowedPattern.test(comments.value)) {
        error.textContent = "Error: Illegal Character!";
        comments.classList.add('bad_input');

        let errors = "Comment Error (Bad Character): " + lastChar;
        form_errors.push(errors);
    } else {
        error.textContent = "No Errors";
    }	


    if (cnt > 200) {
        info.textContent = "Too many characters!";  
    } else {
        info.textContent = "Characters Remaining: " + (200 - cnt);
    }

    let ratio = cnt / 200;
    let redComponent = Math.floor(255 * ratio);
    info.style.color = `rgb(${redComponent}, 0, 0)`;

    setTimeout(() => {
        comments.classList.remove('bad_input');
    }, 100);

    setTimeout(() => {
        error.classList.add('fade-out');
    }, 1000);
    });

    form.addEventListener("submit", async function(event) {
    event.preventDefault();
        if (form.checkValidity() && commentAllowedPattern.test(comments.value) && !email.validity.typeMismatch && nameAllowedPattern.test(name.value)) {
        console.log('working');

        const form = event.target;
        const formData = new FormData(form);

        formData.append("form-errors", JSON.stringify(form_errors));

        try {
            const response = await fetch("https://httpbin.org/post", {
            method: "POST",
            body: formData,
            });

            console.log(await response.json());
        } catch (e) {
            console.error(e);
        }

        let str = "";
        for (const [key, value] of formData.entries()) {
            str+=(`${key}: ${value}\n`);
        } 

        console.log(str);
        } 
    });