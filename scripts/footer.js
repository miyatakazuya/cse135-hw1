/* <footer>    
<nav>

  <a href="https://www.linkedin.com/in/kazmiyata/">
    <img src="/media/icons8-linkedin.svg" alt="Linkedin" width="40" height="40">
  </a>

   <a href="https://github.com/miyatakazuya">
    <img src="/media/icons8-github.svg" alt="Github" width="40" height="40">
   </a>

   <a href="mailto:kazuyamiyata18@gmail.com">
    <img src="/media/Minduka-mail.svg" alt="Linkedin" width="40" height="40">
   </a>
</nav>
</footer> */



class FooterComponent extends HTMLElement {
    constructor() {
        super();
    }

    connectedCallback() {
        this.nav = document.createElement("nav");
        
        this.linkedin = document.createElement("a");
        this.linkedin.setAttribute("href", "https://www.linkedin.com/in/kazmiyata/");
        this.linkedinSvg = document.createElement("img");
        this.linkedinSvg.setAttribute("src", "/media/icons8-linkedin.svg");
        this.linkedinSvg.setAttribute("alt", "Linkedin");
        this.linkedinSvg.setAttribute("width", "40");
        this.linkedinSvg.setAttribute("height", "40");
        this.linkedin.appendChild(this.linkedinSvg);

        this.github = document.createElement("a");
        this.github.setAttribute("href", "https://github.com/miyatakazuya");
        this.githubSvg = document.createElement("img");
        this.githubSvg.setAttribute("src", "/media/icons8-github.svg");
        this.githubSvg.setAttribute("alt", "Github");
        this.githubSvg.setAttribute("width", "40");
        this.githubSvg.setAttribute("height", "40");
        this.github.appendChild(this.githubSvg);

        this.mail = document.createElement("a");
        this.mail.setAttribute("href", "mailto:kazuyamiyata18@gmail.com");
        this.mailSvg = document.createElement("img");
        this.mailSvg.setAttribute("src", "/media/icons8-mail-48.png");
        this.mailSvg.setAttribute("alt", "Email");
        this.mailSvg.setAttribute("width", "40");
        this.mailSvg.setAttribute("height", "40");
        this.mail.appendChild(this.mailSvg);
        
        this.nav.appendChild(this.linkedin);
        this.nav.appendChild(this.github);
        this.nav.appendChild(this.mail);

        this.appendChild(this.nav);
    }
}

customElements.define('footer-nav', FooterComponent);