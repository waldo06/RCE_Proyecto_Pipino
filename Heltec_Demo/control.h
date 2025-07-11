#pragma once

const char htmlControl[] PROGMEM = R"rawliteral(
  <!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <title>Estado de Motores</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    body {
      background-color: #111;
      color: #fff;
      font-family: Arial, sans-serif;
      text-align: center;
      padding: 10px;
    }

    h1 {
      margin-bottom: 20px;
    }

    .motor-grid {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(120px, 1fr));
      gap: 15px;
      max-width: 1000px;
      margin: 0 auto;
    }

    .motor {
      background-color: #222;
      border-radius: 10px;
      padding: 10px;
      box-shadow: 0 0 8px #000;
    }

    .motor h2 {
      margin: 0 0 10px 0;
      font-size: 1rem;
    }

    .estado {
      width: 40px;
      height: 40px;
      margin: 0 auto;
      border-radius: 50%;
      background-color: gray; /* estado por defecto */
      box-shadow: 0 0 10px #444;
    }

    .verde { background-color: #0f0; }
    .rojo  { background-color: #f00; }
    .amarillo { background-color: #ff0; }
  </style>
</head>
<body>
  <h1>Estado de Motores</h1>

  <div class="motor-grid" id="motorGrid">
    <!-- Se generan dinámicamente desde JS -->
  </div>

  <script>
    const NUM_MOTORES = 20;

    function crearMotores() {
      const grid = document.getElementById("motorGrid");
      for (let i = 1; i <= NUM_MOTORES; i++) {
        const div = document.createElement("div");
        div.className = "motor";
        div.innerHTML = `
          <h2>Motor ${i}</h2>
          <div class="estado" id="estado${i}"></div>
        `;
        grid.appendChild(div);
      }
    }

    function actualizarEstados() {
      fetch("/estado.json")
        .then(res => res.json())
        .then(data => {
          for (let i = 1; i <= NUM_MOTORES; i++) {
            const estado = data["motor" + i]; // 'verde', 'rojo' o 'amarillo'
            const el = document.getElementById("estado" + i);
            el.className = "estado " + estado;
          }
        })
        .catch(err => console.error("Error cargando estado:", err));
    }

    crearMotores();
    setInterval(actualizarEstados, 1000); // actualiza cada 1 segundo
  </script>
</body>
</html>

  )rawliteral";