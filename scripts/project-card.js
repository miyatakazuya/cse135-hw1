
// <project-card>
//     <picture>
//         <source></source>
//         <img></img>
//     </picture>
//     <div class="info">
//      <h2></h2>
//      <p></p>
//      <div class="skills"></div>
//      <a></a>
//     </div>
// </project-card>


class ProjectCardComponent extends HTMLElement {
    constructor() {
        super();
    }

    connectedCallback() {

        // Picture <picture>
        this.projectPicture = document.createElement('picture');

        let defaultImage;
        if (this.hasAttribute('data-image-default')) {
            defaultImage = this.getAttribute('data-image-default');
        } else {
            defaultImage = "../images/default-featured-image.jpg";
        }

        this.source = document.createElement('source');
        this.source.setAttribute('srcset', defaultImage);
        this.source.setAttribute('media','(min-width: 700px)');
        this.source.setAttribute('type','image/jpg');

        let altImage;
        if (this.hasAttribute('data-image-alt')) {
            altImage = this.getAttribute('data-image-alt');
        } else {
            altImage = "../images/default-featured-image.jpg";
        }

        this.image = document.createElement('img');
        this.image.setAttribute('src', altImage);
        this.image.setAttribute('width', '1000');
        this.image.setAttribute('alt', 'Toothless AUV');
        
        this.projectPicture.appendChild(this.source);
        this.projectPicture.appendChild(this.image);
        this.appendChild(this.projectPicture);

        // Info <div>
        this.info = document.createElement('div');
        this.info.setAttribute('class', 'info');
        this.appendChild(this.info);

        // Header <h2>
        this.projectHeader = document.createElement('h3');

        let headerText;
        if (this.hasAttribute('data-header')) {
            headerText = this.getAttribute('data-header');
        } else {
            headerText = "Default Project";
        }
        this.projectHeader.textContent = headerText;
        this.info.appendChild(this.projectHeader);
        
        // Description <p>

        this.description = this.querySelector('.description');
        if (this.description) {
            this.removeChild(this.description);
            this.info.appendChild(this.description);
        } else {
            this.description = document.createElement('p');
            this.description.textContent = 'Short Project Description';
            this.info.appendChild(this.description);
        }

        // this.description = document.createElement('p');
        // this.description.setAttribute('name', 'description');
        // this.description.textContent = 'Short Project Description';
        // this.info.appendChild(this.description);    

        // Used Skills <div>
        this.skills = document.createElement('div');
        this.skills.setAttribute('class', 'skills');
        this.info.appendChild(this.skills);

        // More Info <a>
        this.hyperlink = document.createElement('a');
        let hyperlinkText;
        if (this.hasAttribute('data-hyperlink')) {
            hyperlinkText = this.getAttribute('data-hyperlink');
        } else {
            hyperlinkText = 'https://github.com/miyatakazuya';
        }
        this.hyperlink.setAttribute('href', hyperlinkText);
        this.hyperlink.textContent = 'More Information Here';
        this.info.appendChild(this.hyperlink);
    }
}

customElements.define('project-card', ProjectCardComponent);