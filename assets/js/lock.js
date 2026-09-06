const FORMATION_HASHES = {
  arduino: "19b1ca833ebc83cfd7bee78a7737cd3a71d0d1ae9339e3e255469c0f492585c4",
  frontend: "f3e2dcdbc0bdc6d1aa7be27774f1e77703ac56fd0a5e371b53b4a4932e368dcc",
  backend: "f88ff12984bbaaabea6acc59aa4936b6ac3c1b69afa1c6dc3ac2f2881239b137",
  cybersecurite: "961ab2afeec25317f1c9ef72854982be2773c3825d0f49e540ef2b7660cc0a52",
  informatique: "3b668cc70504ded652dcda4ef49a36539a193c3fabf7dea590bf87145c56c41b"
};

async function sha256(value) {
  const data = new TextEncoder().encode(value);
  const hash = await crypto.subtle.digest("SHA-256", data);
  return [...new Uint8Array(hash)].map(b => b.toString(16).padStart(2, "0")).join("");
}

async function unlockFormation(key, password) {
  return (await sha256(password)) === FORMATION_HASHES[key];
}

function initLock(key, formationName) {
  const form = document.querySelector("#access-form");
  const input = document.querySelector("#password");
  const message = document.querySelector("#access-message");
  const locked = document.querySelector("#locked-content");
  const protectedContent = document.querySelector("#protected-content");
  const storageKey = `goma-pro-devs-access-${key}`;

  if (sessionStorage.getItem(storageKey) === "granted") {
    locked.hidden = true;
    protectedContent.hidden = false;
    return;
  }

  form.addEventListener("submit", async (event) => {
    event.preventDefault();
    message.textContent = "Vérification en cours...";
    message.className = "access-message";
    const valid = await unlockFormation(key, input.value);
    if (valid) {
      sessionStorage.setItem(storageKey, "granted");
      locked.hidden = true;
      protectedContent.hidden = false;
    } else {
      message.textContent = "Mot de passe incorrect. Accès refusé.";
      message.className = "access-message error";
      input.select();
    }
  });
}
