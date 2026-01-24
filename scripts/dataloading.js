window.addEventListener('DOMContentLoaded', async () => {
    document.getElementById("remote").addEventListener('click', async () => {
        console.log("DOM Content loaded");
        const url = "https://api.jsonbin.io/v3/b/67d62d578960c979a57262f8";
        try {
            const response = await fetch(url);
            if (!response.ok) {
                throw new Error(`Response status: ${response.status}`);
            }

            document.getElementById("parent").innerHTML = "";

            const jsonData = await response.json();
            console.log(jsonData);
            jsonData.record.projects.forEach(project => {
                console.log(project);
            
                window.projectItem = document.createElement("project-card");

                window.projectItem.setAttribute("data-image-default", project.image_default);
                window.projectItem.setAttribute("data-image-alt", project.image_alt);  
                window.projectItem.setAttribute("data-header", project.title);
                window.projectItem.setAttribute("data-hyperlink", project.link);

                window.dsc = document.createElement("p");
                window.dsc.setAttribute("class", "description");
                window.dsc.textContent = project.description;   
                window.projectItem.appendChild(window.dsc);

                console.log(window.projectItem);
                document.getElementById("parent").appendChild(window.projectItem);
            });

        } catch (error) {
            console.error(error.message);
        }
    })

    // Data to be stored in localStorage
    const data = {
        "projects": [
          {
            "title": "Triton UAS - Local Version",
            "description": "Competion aircraft; OBC (Onboard Computer) programmed in C++ and handles autonomous state management.",
            "link": "https://github.com/tritonuas/obcpp",
            "image_default": "https://www.dropbox.com/scl/fi/e32eakxg2clt5o1g4u7lq/toothless-compressed.jpg?rlkey=ine1xc2201mps1lbtvat8rbhx&st=0qig3pag&dl=1",
            "image_alt": "https://www.dropbox.com/scl/fi/e32eakxg2clt5o1g4u7lq/toothless-compressed.jpg?rlkey=ine1xc2201mps1lbtvat8rbhx&st=0qig3pag&dl=1"
          },
          {
            "title": "Istari UAV",
            "description": "A lightweight, PLA printed aircraft optimized for low-cost iterations of client aircraft models.",
            "link": "https://github.com/tritonuas/gcs",
            "image_default": "https://www.dropbox.com/scl/fi/gzzyrfkkwrzq6ruhi6jp8/istari-compressed.jpg?rlkey=fapkc7jwkpvp3owctihdq79my&st=u5s3bjw5&dl=1",
            "image_alt": "https://www.dropbox.com/scl/fi/gzzyrfkkwrzq6ruhi6jp8/istari-compressed.jpg?rlkey=fapkc7jwkpvp3owctihdq79my&st=u5s3bjw5&dl=1"
          }
        ]
      };
      
    localStorage.setItem('projectsData', JSON.stringify(data));
    
    document.getElementById("local").addEventListener('click', async () => {
        document.getElementById("parent").innerHTML = "";
        
        const storedData = JSON.parse(localStorage.getItem('projectsData'));
        storedData.projects.forEach(project => {
            console.log(project);
        
            window.projectItem = document.createElement("project-card");

            window.projectItem.setAttribute("data-image-default", project.image_default);
            window.projectItem.setAttribute("data-image-alt", project.image_alt);  
            window.projectItem.setAttribute("data-header", project.title);
            window.projectItem.setAttribute("data-hyperlink", project.link);

            window.dsc = document.createElement("p");
            window.dsc.setAttribute("class", "description");
            window.dsc.textContent = project.description;
            window.projectItem.appendChild(window.dsc);

            console.log(window.projectItem);
            document.getElementById("parent").appendChild(window.projectItem);
        });
    });


});

