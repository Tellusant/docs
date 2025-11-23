---
title: Search
layout: default
permalink: /search/
---

<h1>Search</h1>

<label for="search-input" class="visually-hidden">Search</label>
<input id="search-input" type="search" placeholder="Search…" 
       style="width:100%;max-width:640px;padding:0.6rem;font-size:1rem;border:1px solid #ddd;border-radius:8px">

<p id="search-meta" style="margin:0.5rem 0 1rem;color:#666;"></p>
<div id="search-results" aria-live="polite" aria-busy="false"></div>

<script src="https://cdn.jsdelivr.net/npm/lunr/lunr.min.js"></script>
<script src="{{ "/assets/js/search.js" | relative_url }}"></script>

<style>
.visually-hidden{position:absolute;left:-9999px}
.search-hit{padding:0.75rem 0;border-bottom:1px solid #eee}
.search-hit a{font-weight:600;text-decoration:none}
.search-hit p{margin:0.25rem 0 0;color:#444}
mark{background:#ffff00;}
</style>
This page will live at:
https://tellusant.github.io/docs/search/

3. Add /docs/assets/js/search.js (baseurl-aware)
Create the JS file at docs/assets/js/search.js with YAML front matter so Jekyll processes Liquid inside it:

javascript
Copy code
---
---
// search.js - client-side search using Lunr and search.json

(function () {
  const INPUT = document.getElementById("search-input");
  const RESULTS = document.getElementById("search-results");
  const META = document.getElementById("search-meta");

  // Jekyll will expand this to /docs/search.json
  const INDEX_URL = "{{ "/search.json" | relative_url }}";

  let documents = [];
  let idx = null;

  function debounce(fn, ms) {
    let t;
    return (...args) => {
      clearTimeout(t);
      t = setTimeout(() => fn.apply(this, args), ms);
    };
  }

  async function loadIndex() {
    const res = await fetch(INDEX_URL);
    documents = await res.json();

    idx = lunr(function () {
      this.ref("url");
      this.field("title", { boost: 10 });
      this.field("content");
      documents.forEach(doc => this.add(doc));
    });
  }

  function highlight(text, terms) {
    if (!terms.length) return text;
    try {
      const term = terms[0].replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
      const re = new RegExp(`(${term})`, "ig");
      return text.replace(re, "<mark>$1</mark>");
    } catch {
      return text;
    }
  }

  function snippet(content, terms, maxLen = 180) {
    if (!content) return "";
    const lower = content.toLowerCase();
    let idx = -1;
    for (const t of terms) {
      const i = lower.indexOf(t.toLowerCase());
      if (i !== -1) { idx = i; break; }
    }
    let start = Math.max(0, idx - 60);
    let snip = content.slice(start, start + maxLen);
    if (start > 0) snip = "…" + snip;
    if (start + maxLen < content.length) snip = snip + "…";
    return highlight(snip, terms);
  }

  function render(results, terms) {
    RESULTS.innerHTML = "";
    if (!results.length) {
      META.textContent = "No results";
      return;
    }
    META.textContent = `${results.length} result${results.length > 1 ? "s" : ""}`;

    results.slice(0, 50).forEach(({ ref }) => {
      const doc = documents.find(d => d.url === ref);
      if (!doc) return;

      const div = document.createElement("div");
      div.className = "search-hit";

      const a = document.createElement("a");
      a.href = doc.url;
      a.innerHTML = highlight(doc.title, terms);

      const p = document.createElement("p");
      p.innerHTML = snippet(doc.content, terms);

      div.appendChild(a);
      div.appendChild(p);
      RESULTS.appendChild(div);
    });
  }

  const onInput = debounce(() => {
    const q = INPUT.value.trim();
    if (!q || !idx) {
      META.textContent = q ? "Index loading…" : "";
      RESULTS.innerHTML = "";
      return;
    }
    try {
      const terms = q.split(/\s+/).filter(Boolean);
      const query = terms.map(t => `${t}*`).join(" ");
      const results = idx.search(query);
      render(results, terms);
    } catch (e) {
      console.warn(e);
      META.textContent = "Search error";
    }
  }, 120);

  INPUT?.addEventListener("input", onInput);

  let loaded = false;
  function ensureLoaded() {
    if (loaded) return;
    loaded = true;
    loadIndex().then(onInput);
  }

  window.addEventListener("load", ensureLoaded);
  INPUT?.addEventListener("focus", ensureLoaded);
})();
