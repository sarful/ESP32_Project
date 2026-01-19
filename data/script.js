function loadChat() {
  fetch("/read")
    .then((res) => res.text())
    .then((data) => {
      const box = document.getElementById("chatBox");
      box.innerHTML = data || "<p class='status'>No messages</p>";
      box.scrollTop = box.scrollHeight;
    })
    .catch(() => {
      document.getElementById("chatBox").innerHTML =
        "<p class='status'>ESP32 not responding</p>";
    });
}

function sendMessage() {
  const input = document.getElementById("message");
  const msg = input.value.trim();
  if (!msg) return;

  fetch("/send?msg=" + encodeURIComponent(msg));
  input.value = "";
}

setInterval(loadChat, 1000);
loadChat();
