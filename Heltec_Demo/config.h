#pragma once

const char htmlConfig[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Configuración WiFi y LoRa</title>
  <style>
    body {
      background-color: #0d0d0d;
      color: #fff;
      font-family: Arial, sans-serif;
      display: flex;
      flex-direction: column;
      align-items: center;
      padding: 20px;
    }

    h2 {
      color: #1e90ff;
      margin-top: 30px;
    }

    form {
      background-color: #111;
      padding: 20px;
      border-radius: 10px;
      width: 100%;
      max-width: 400px;
    }

    label {
      display: block;
      margin-top: 15px;
      margin-bottom: 5px;
      font-weight: bold;
    }

    input, select {
      width: 100%;
      padding: 10px;
      border: none;
      border-radius: 5px;
      background-color: #222;
      color: #fff;
    }

    button {
      margin-top: 20px;
      width: 100%;
      padding: 12px;
      font-size: 1em;
      border: none;
      border-radius: 10px;
      background-color: #00bfff;
      color: white;
      cursor: pointer;
    }

    button:hover {
      background-color: #0099cc;
    }
  </style>
</head>
<body>
  <h2>Configurar conexión WiFi</h2>
  <form id="wifiForm">
    <label for="ssid">Nombre de red (SSID)</label>
    <input type="text" id="ssid" name="ssid" placeholder="Nombre de red (SSID)">

    <label for="password">Contraseña WiFi</label>
    <input type="password" id="password" name="password" placeholder="Contraseña WiFi">
  </form>

  <h2>Configurar LoRa</h2>
  <form id="loraForm">
    <label for="frecuencia">Frecuencia (MHz)</label>
    <input type="number" id="frecuencia" name="frecuencia" value="915.0" step="0.1">

    <label for="sf">Spreading Factor (SF)</label>
    <select id="sf" name="sf">
      <option>SF7</option>
      <option>SF8</option>
      <option>SF9</option>
      <option>SF10</option>
      <option>SF11</option>
      <option>SF12</option>
    </select>

    <label for="bandwidth">Ancho de banda (kHz)</label>
    <select id="bandwidth" name="bandwidth">
      <option>125</option>
      <option>250</option>
      <option>500</option>
    </select>

    <label for="codingRate">Coding Rate</label>
    <select id="codingRate" name="codingRate">
      <option>4/5</option>
      <option>4/6</option>
      <option>4/7</option>
      <option>4/8</option>
    </select>

    <label for="syncWord">Sync Word (0–255)</label>
    <input type="number" id="syncWord" name="syncWord" min="0" max="255" value="18">

    <label for="power">Potencia de salida (dBm)</label>
    <select id="power" name="power">
      <option>13</option>
      <option>15</option>
      <option selected>17</option>
      <option>20</option>
    </select>

    <label for="preambulo">Preámbulo (símbolos)</label>
    <input type="number" id="preambulo" name="preambulo" value="8">

    <button type="submit">Guardar</button>
  </form>
</body>
</html>
)rawliteral";