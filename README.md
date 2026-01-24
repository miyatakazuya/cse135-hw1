# kazuya-miyata.github.io

Personal Website for CSE134B

## Changelog (Part 3)
**HTML Improvements:**
- Replaced `footer` with custom element `footer-nav`. 
- Enforced usage of different header types because I was overusing `<h2>` for presentational purposes, so I replaced many of them with `<h3>` or `<h4>`.
- Changed SVG to be filled icons for the footer for clarity and consistency with other icons. 
- Improved meta tag usage to increase SEO scores. 
- Increased use of alt text of images for accessibility as increased JS might lead to slower loading times/timeouts. 

**CSS Improvements:**
- Edited margins of Project Pages to align with header properly. 
- Changed custom font to use font-face, with fallback to a serif or sans serif font so there is a default font at all times.
- Improved Button Hover animations using better colors to suit the new color themes.
- Improved Margins in About me page, changed Image size so that it fits on landing. Also added borders to image to diffrentiate from light background.

**JS Improvements:**
- Created an additional new element `footer-nav`, which replaces the old footers in each page. This was done because the same exact html was repeated through each page, and I though creating a new html element would make editing the nav easier in the future, as well as remove repeated markup throughout the pages.
- Created new `contact-form.js` to keep separation of concerns and add visual clarity to html file.
- Reduced instances of weak typing on form and project variables to prevent any implict type coercion. 
