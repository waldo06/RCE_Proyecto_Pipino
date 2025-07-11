#pragma once

const char htmlInicio[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>RCE Ingeniería</title>
  <style>
    :root {
      color-scheme: dark;
    }

    body {
      margin: 0;
      padding: 0;
      background-color: #0d0d0d;
      color: #f2f2f2;
      font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen, Ubuntu, Cantarell, sans-serif;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      min-height: 100vh;
      text-align: center;
      position: relative;
    }

    h1 {
      font-size: 2em;
      margin-top: 10px;
      margin-bottom: 20px;
    }

    .titulo {
      font-size: 4em;
      font-weight: bold;
      color: #4CAF50;
      margin-bottom: 0;
      text-shadow: 1px 1px 0 #D32F2F, -1px 1px 0 #D32F2F, 1px -1px 0 #D32F2F, -1px -1px 0 #D32F2F;
    }

    .subtitulo {
      font-size: 1.5em;
      color: #bbbbbb;
      margin-top: 0;
      margin-bottom: 0;
    }

    .descripcion {
      font-size: 1em;
      color: #999999;
      margin-top: 5px;
      margin-bottom: 30px;
    }

    .progress-container {
      width: 80%;
      height: 8px;
      background-color: #444;
      border-radius: 4px;
      overflow: hidden;
      margin-top: 10px;
    }

    .progress-bar {
      width: 0%;
      height: 100%;
      background: linear-gradient(90deg, #00ffcc, #00bfff);
      animation: cargar 3s linear forwards;
    }

    .footer {
      position: absolute;
      bottom: 10px;
      font-size: 0.9em;
      color: #777;
    }

    @keyframes cargar {
      0% { width: 0%; }
      100% { width: 100%; }
    }
  </style>
 <script>
  setTimeout(() => {
    window.location.href = "/index";
  }, 3200);
</script>
</head>
<body>
  <h1>Bienvenidos</h1>
  <div class="titulo">RCE</div>
  <div class="subtitulo">Ingeniería</div>
  <div class="descripcion">REDES, CONTROL Y ENERGÍA</div>
  <div class="progress-container">
    <div class="progress-bar"></div>
  </div>
  <div class="footer">Industria Argentina</div>
</body>
</html>

)rawliteral";
