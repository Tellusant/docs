/* Custom header tweaks for site-name and description */
.site-header-wrapper {
  text-align: center;
  padding: 1.5rem 0;
  border-bottom: 1px solid #eaeaea;
}

.site-name {
  font-size: 1.75rem;
  font-weight: 600;
  color: #333;
  margin: 0;
}

.site-description {
  font-size: 1rem;
  color: #777;
  margin: 0.25rem 0 0;
}
/* === Sticky Header Styling === */
.site-header {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  background-color: #fff; /* Matches Minima’s default white background */
  border-bottom: 1px solid #eaeaea;
  z-index: 1000;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.05);
}

/* Add padding so content isn’t hidden behind header */
body {
  padding-top: 90px; /* Adjust if your header is taller or shorter */
}

/* Keep header text centered and readable */
.site-header-wrapper {
  text-align: center;
  padding: 1.25rem 0;
}

.site-name {
  font-size: 1.75rem;
  font-weight: 600;
  margin: 0;
}

.site-name a {
  text-decoration: none;
  color: inherit;
}

.site-name a:hover {
  text-decoration: underline;
}

.site-description {
  font-size: 1rem;
  color: #777;
  margin: 0.25rem 0 0;
}
