/* ======================
   HERO ANIMATION
====================== */
setTimeout(() => {
  const text = "You Know Cloning";
  let i = 0;
  const hero = document.getElementById("heroText");

  const interval = setInterval(() => {
    hero.textContent = text.slice(0, i);
    i++;
    if (i > text.length) {
      clearInterval(interval);
      setTimeout(() => {
        document.getElementById("system")
          .scrollIntoView({ behavior: "smooth" });
      }, 800);
    }
  }, 100);
}, 1000);

/* ======================
   AUDIO STATUS
====================== */
document.getElementById("audioUpload").addEventListener("change", e => {
  const status = document.getElementById("fileStatus");
  if (e.target.files.length) {
    status.textContent = "File uploaded ✔ Checking compatibility...";
  }
});

/* ======================
   THEME SYSTEM (REUSABLE)
====================== */
function setTheme(theme) {
  const root = document.documentElement;

  if (theme === "blue") {
    root.style.setProperty("--accent-blue", "#00cfff");
    root.style.setProperty("--accent-purple", "#7f5cff");
  }
  if (theme === "purple") {
    root.style.setProperty("--accent-blue", "#a855f7");
    root.style.setProperty("--accent-purple", "#ec4899");
  }
  if (theme === "dark") {
    root.style.setProperty("--bg-main", "#05070f");
  }
  if (theme === "light") {
    root.style.setProperty("--bg-main", "#f5f7ff");
  }
}
