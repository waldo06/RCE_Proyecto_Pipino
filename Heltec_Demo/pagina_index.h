#pragma once

const char htmlIndex[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>RCE - Inicio</title>
  <style>
    body {
      margin: 0;
      padding: 0;
      background-color: #0d0d0d;
      color: white;
      font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      height: 100vh;
      text-align: center;
    }

    h1 {
      font-size: 1.6em;
      margin-bottom: 40px;
    }

    button {
      width: 220px;
      padding: 14px;
      margin: 12px;
      font-size: 1em;
      border: none;
      border-radius: 12px;
      cursor: pointer;
      background-color: #1e90ff;
      color: white;
      transition: background-color 0.3s;
    }

    button:hover {
      background-color: #00bfff;
    }
  </style>
</head>
<body>
  <h1>¿Qué desea hacer?</h1>
  <button onclick="location.href='/control'">Puesto de Control</button>
  <button onclick="location.href='/config'">Configuraciones</button>
</body>
</html>

)rawliteral";
