// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const { ipcRenderer } = require('electron');

const activateBtn = document.getElementById('activate-btn');

activateBtn.addEventListener('click', event => {
  const licenseKey = document.getElementById('license-key').value;
  ipcRenderer.send('click-activate-btn', licenseKey);
});
