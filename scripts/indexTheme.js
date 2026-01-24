function setTheme(theme) {
    const root = document.documentElement;

    if (theme === 'light') {
        root.style.setProperty('background-color', 'var(--bg-color-light)');
        root.style.setProperty('color', 'var(--text-color-light)');
    } else {
        root.style.setProperty('background-color', 'var(--bg-color-dark)');
        root.style.setProperty('color', 'var(--text-color-dark)');
    }
}

function toggleTheme() {
    console.log('toggling theme');
    const currTheme = localStorage.getItem('theme') || 'light';
    const newTheme = currTheme === 'light'? 'dark': 'light';
    localStorage.setItem('theme', newTheme);
    setTheme(newTheme);
}

function setSavedTheme() {
    const savedTheme = localStorage.getItem('theme');
    if(savedTheme) {
        setTheme(savedTheme);
        document.getElementById('toggleTheme').checked = (savedTheme === 'dark');
    }
}

document.addEventListener('DOMContentLoaded', setSavedTheme);