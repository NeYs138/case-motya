<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CS2 Cases - Site Prototype</title>
    <style>
        :root {
            --bg-main: #0f172a;
            --bg-sidebar: #1e293b;
            --bg-card: #1e293b;
            --text-main: #f8fafc;
            --text-muted: #94a3b8;
            --accent: #f59e0b;
            --accent-hover: #d97706;
            --btn-green: #10b981;
            --btn-green-hover: #059669;
            --btn-red: #ef4444;
            --btn-red-hover: #dc2626;
            --btn-btc: #f7931a; /* Цвет биткоина */
            --border-color: #334155;
        }

        * { box-sizing: border-box; margin: 0; padding: 0; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; }

        body { background-color: var(--bg-main); color: var(--text-main); display: flex; min-height: 100vh; }

        /* Боковая панель */
        .sidebar {
            width: 250px; background-color: var(--bg-sidebar); padding: 20px;
            display: flex; flex-direction: column; gap: 10px;
            border-right: 1px solid var(--border-color); position: fixed; height: 100vh; overflow-y: auto;
        }

        .sidebar h2 { color: var(--accent); text-align: center; margin-bottom: 20px; font-size: 24px; text-transform: uppercase; }

        .nav-btn {
            background: transparent; border: 1px solid var(--border-color); color: var(--text-main);
            padding: 12px; border-radius: 8px; cursor: pointer; font-size: 16px; text-align: left; transition: 0.2s;
        }

        .nav-btn:hover, .nav-btn.active { background-color: var(--accent); color: #000; border-color: var(--accent); font-weight: bold; }

        .exchange-box {
            margin-top: auto; border-top: 1px solid var(--border-color); padding-top: 20px;
        }
        .exchange-box h3 { font-size: 14px; margin-bottom: 10px; color: var(--text-muted); text-align: center; }
        .ex-btn { width: 100%; margin-bottom: 10px; padding: 8px; font-size: 12px; background: var(--btn-btc); border: none; color: #fff; font-weight: bold; border-radius: 6px; cursor: pointer; }
        .ex-btn:hover { opacity: 0.8; }

        /* Контент */
        .main-content { margin-left: 250px; padding: 20px; width: calc(100% - 250px); flex-grow: 1; }

        /* Шапка */
        .header {
            display: flex; justify-content: space-between; align-items: center;
            background-color: var(--bg-sidebar); padding: 15px 25px; border-radius: 12px;
            margin-bottom: 20px; border: 1px solid var(--border-color);
        }

        .balances { display: flex; gap: 20px; font-size: 20px; font-weight: bold; }
        .rub-bal { color: var(--btn-green); }
        .btc-bal { color: var(--btn-btc); }

        /* Сетка кейсов */
        .cases-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(220px, 1fr)); gap: 20px; }

        .case-card {
            background-color: var(--bg-card); border-radius: 12px; padding: 15px; text-align: center;
            border: 1px solid var(--border-color); transition: transform 0.2s, box-shadow 0.2s;
            display: flex; flex-direction: column; justify-content: space-between;
        }

        .case-card:hover { transform: translateY(-5px); box-shadow: 0 10px 20px rgba(0,0,0,0.5); border-color: var(--accent); }
        .case-card.btc-card { border-color: var(--btn-btc); box-shadow: 0 0 15px rgba(247, 147, 26, 0.2); }
        .case-card.btc-card:hover { border-color: #ffb347; box-shadow: 0 0 20px rgba(247, 147, 26, 0.4); }

        .case-image {
            width: 100%; height: 140px; background: linear-gradient(135deg, #2a3a52 0%, #1a2536 100%);
            border-radius: 8px; margin-bottom: 15px; display: flex; align-items: center; justify-content: center; font-size: 40px;
        }
        .btc-card .case-image { background: linear-gradient(135deg, #4a2c00 0%, #1a1000 100%); }

        .case-name { font-size: 16px; font-weight: bold; margin-bottom: 5px; }
        .case-price-rub { color: var(--accent); font-weight: bold; font-size: 18px; margin-bottom: 15px; }
        .case-price-btc { color: var(--btn-btc); font-weight: bold; font-size: 18px; margin-bottom: 15px; }

        .btn-open { background-color: var(--accent); color: #000; border: none; padding: 10px; border-radius: 6px; font-weight: bold; cursor: pointer; transition: 0.2s; width: 100%; }
        .btn-open:hover { background-color: var(--accent-hover); }
        .btn-open.btc-btn { background-color: var(--btn-btc); color: #fff; }
        .btn-open.btc-btn:hover { background-color: #d97b0d; }

        /* Инвентарь */
        .inventory-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(180px, 1fr)); gap: 15px; }
        .inv-item { background-color: var(--bg-card); border-radius: 8px; padding: 10px; text-align: center; border: 1px solid var(--border-color); }
        .inv-item img { width: 100%; height: 90px; object-fit: contain; margin-bottom: 10px; }
        .inv-item-name { font-size: 12px; margin-bottom: 5px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }
        .inv-item-price { color: var(--accent); font-weight: bold; font-size: 14px; margin-bottom: 10px; }
        .btn-sell { background-color: var(--btn-red); color: #fff; border: none; padding: 6px 12px; border-radius: 4px; cursor: pointer; font-size: 12px; width: 100%; }
        .btn-sell:hover { background-color: var(--btn-red-hover); }

        /* Апгрейд */
        .upgrade-container { background-color: var(--bg-card); padding: 20px; border-radius: 12px; border: 1px solid var(--border-color); }
        .upgrade-slots { display: flex; justify-content: center; align-items: center; gap: 30px; margin-bottom: 30px; }
        .slot { width: 200px; height: 150px; border: 2px dashed var(--border-color); border-radius: 8px; display: flex; flex-direction: column; align-items: center; justify-content: center; background-color: rgba(0,0,0,0.2); }
        .slot img { max-width: 120px; max-height: 80px; object-fit: contain; }
        
        .multipliers { display: flex; justify-content: center; gap: 10px; flex-wrap: wrap; margin-bottom: 20px; }
        .mult-btn { background-color: var(--bg-main); color: var(--text-main); border: 1px solid var(--border-color); padding: 10px 20px; border-radius: 6px; cursor: pointer; font-weight: bold; }
        .mult-btn:hover { border-color: var(--accent); }
        .mult-btn.active { background-color: var(--accent); color: #000; border-color: var(--accent); }
        
        .btn-upgrade { background-color: var(--btn-green); color: #fff; border: none; padding: 15px 40px; border-radius: 8px; font-size: 18px; font-weight: bold; cursor: pointer; display: block; margin: 0 auto; }
        .btn-upgrade:hover { background-color: var(--btn-green-hover); }

        /* Модальное окно */
        .modal { display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0,0,0,0.8); justify-content: center; align-items: center; z-index: 1000; }
        .modal-content { background: var(--bg-card); padding: 30px; border-radius: 12px; text-align: center; border: 2px solid var(--accent); max-width: 400px; }
        .modal-content img { max-width: 200px; margin-bottom: 15px; }
        .modal-content h3 { margin-bottom: 10px; }
        .modal-content p { color: var(--accent); font-size: 20px; font-weight: bold; margin-bottom: 20px; }
        .modal-content button { background: var(--accent); border: none; padding: 10px 30px; border-radius: 6px; font-weight: bold; cursor: pointer; }

        /* Уведомления */
        #notification { position: fixed; top: 20px; right: 20px; background: var(--btn-red); color: white; padding: 15px 25px; border-radius: 8px; font-weight: bold; display: none; z-index: 2000; }
    </style>
</head>
<body>

    <!-- Боковое меню -->
    <div class="sidebar">
        <h2>Case-Battle</h2>
        <button class="nav-btn active" onclick="switchTab('cases')">Кейсы</button>
        <button class="nav-btn" onclick="switchTab('inventory')">Инвентарь</button>
        <button class="nav-btn" onclick="switchTab('upgrade')">Апгрейд</button>
        
        <!-- Обменник валют -->
        <div class="exchange-box">
            <h3>Обменник (1 BTC = 50 000 ₽)</h3>
            <button class="ex-btn" onclick="exchangeCurrency('rubToBtc')">Купить 1 BTC за 50к ₽</button>
            <button class="ex-btn" style="background:var(--btn-green);" onclick="exchangeCurrency('btcToRub')">Продать 1 BTC за 50к ₽</button>
        </div>
    </div>

    <!-- Основной контент -->
    <div class="main-content">
        <!-- Шапка -->
        <div class="header">
            <h1 id="page-title">Сериные кейсы</h1>
            <div class="balances">
                <div class="rub-bal">Баланс: <span id="balance-val">0</span> ₽</div>
                <div class="btc-bal">Баланс: <span id="btc-balance-val">0</span> ₿</div>
            </div>
        </div>

        <!-- Раздел Кейсы -->
        <div id="tab-cases" class="tab-content">
            <div class="cases-grid" id="cases-container"></div>
        </div>

        <!-- Раздел Инвентарь -->
        <div id="tab-inventory" class="tab-content" style="display: none;">
            <div class="inventory-grid" id="inventory-container"></div>
        </div>

        <!-- Раздел Апгрейд -->
        <div id="tab-upgrade" class="tab-content" style="display: none;">
            <div class="upgrade-container">
                <div class="upgrade-slots">
                    <div class="slot" id="upgrade-slot-from"><span style="color:var(--text-muted)">Выберите скин</span></div>
                    <div style="font-size: 30px; color: var(--accent);">➔</div>
                    <div class="slot" id="upgrade-slot-to"><span style="color:var(--text-muted)">Результат</span></div>
                </div>
                <h3 style="text-align:center; margin-bottom: 15px;">Выберите множитель / шанс:</h3>
                <div class="multipliers">
                    <button class="mult-btn" onclick="setUpgrade(2, 50, this)">x2 (50%)</button>
                    <button class="mult-btn" onclick="setUpgrade(3.3, 30, this)">30% (x3.3)</button>
                    <button class="mult-btn" onclick="setUpgrade(1.33, 75, this)">75% (x1.33)</button>
                    <button class="mult-btn" onclick="setUpgrade(3, 33, this)">x3 (33%)</button>
                    <button class="mult-btn" onclick="setUpgrade(5, 20, this)">x5 (20%)</button>
                    <button class="mult-btn" onclick="setUpgrade(10, 10, this)">x10 (10%)</button>
                    <button class="mult-btn" onclick="setUpgrade(15, 6.6, this)">x15 (6.6%)</button>
                </div>
                <button class="btn-upgrade" onclick="doUpgrade()">Апгрейд</button>
            </div>
        </div>
    </div>

    <!-- Модальное окно -->
    <div class="modal" id="win-modal">
        <div class="modal-content">
            <h2>Вы выиграли!</h2>
            <img id="modal-img" src="" alt="skin">
            <h3 id="modal-name"></h3>
            <p id="modal-price"></p>
            <button onclick="closeModal()">Забрать</button>
        </div>
    </div>

    <div id="notification"></div>

    <script>
        // --- БАЗА ДАННЫХ ---
        const casesData = [
            { id: 1, name: "Мотя Лох", price: 500, items: [
                { name: "AK-47 | Красная линия", price: 1500, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "USP-S | Поток информации", price: 2200, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "Glock-18 | Блок-18", price: 100, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 2, name: "Арсений Даун", price: 1000, items: [
                { name: "AWP | Азимов", price: 5500, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "Desert Eagle | Поток информации", price: 2100, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "P250 | Пепел", price: 50, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 3, name: "Мотвей Дебил", price: 1500, items: [
                { name: "AK-47 | Вулкан", price: 7400, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "M4A4 | Темукау", price: 1700, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "Negev | Люцифер", price: 100, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 4, name: "Ваня Лошара", price: 2000, items: [
                { name: "AWP | Гунгнир", price: 490000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "M4A1-S | Градиент", price: 11000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "Dual Berettas | Ритуал", price: 20, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 5, name: "Дима Фигня", price: 2500, items: [
                { name: "G3SG1 | Цифровая сетка", price: 10, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "MP5-SD | Невесомый", price: 40, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "P2000 | Импульс", price: 5, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 6, name: "Киберспортсмен", price: 3000, items: [
                { name: "AK-47 | Наследство", price: 1900, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "M4A1-S | Поток информации", price: 10000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "AWP | Азимов", price: 5500, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 7, name: "Коллекционер", price: 3500, items: [
                { name: "M4A1-S | Градиент", price: 11000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "AK-47 | Золотая арабеска", price: 800, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "AWP | Удар молнии", price: 400, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            { id: 8, name: "Перчатки и Ножи", price: 4000, items: [
                { name: "★ Керамбит | Ржавый", price: 45000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "★ Нож-бабочка | Ржавый", price: 80000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                { name: "★ Водительские перчатки | Королевский змей", price: 7000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
            ]},
            // --- БИТКОИН КЕЙС ---
            { 
                id: 9, name: "CRYPTO CASE", price: 0.5, isBtc: true, 
                items: [
                    { name: "AWP | Драконий огонь", price: 150000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                    { name: "★ Нож-бабочка | Градиент", price: 120000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" },
                    { name: "AK-47 | Дикий лотос", price: 25000, img: "https://community.cloudflare.steamstatic.com/economy/image/-9a81dlWLwJ2UUGcVs_nsVtzdOEdtWwKGZZLQHTxDZ7I56KU0Zwwo4NUX4oFJZEHLbXH5ApeO4YmlhxYQknCRvR6a2xbQUtzDxJSpKz3Yl9j18b3f7iPmqzWzIGZk6qqZ7eJlDoBsZ0o3LiTpo2s3Fbs_0VvMWj0dYXEJgY4c0u9Nw/360fx360f" }
                ] 
            }
        ];

        // --- СОСТОЯНИЕ ---
        let state = {
            balance: 10000, // Стартовые рубли
            bitcoins: 1,    // Стартовые биткоины (для теста)
            inventory: []
        };

        // Загрузка сохранений
        if (localStorage.getItem('cs2_balance')) state.balance = parseInt(localStorage.getItem('cs2_balance'));
        if (localStorage.getItem('cs2_bitcoins')) state.bitcoins = parseFloat(localStorage.getItem('cs2_bitcoins'));
        if (localStorage.getItem('cs2_inventory')) state.inventory = JSON.parse(localStorage.getItem('cs2_inventory'));

        // --- ФУНКЦИИ РЕНДЕРА ---
        
        function updateBalanceUI() {
            document.getElementById('balance-val').innerText = state.balance.toLocaleString('ru-RU');
            document.getElementById('btc-balance-val').innerText = state.bitcoins.toFixed(2);
        }

        function saveState() {
            localStorage.setItem('cs2_balance', state.balance);
            localStorage.setItem('cs2_bitcoins', state.bitcoins);
            localStorage.setItem('cs2_inventory', JSON.stringify(state.inventory));
        }

        // Рендер кейсов
        function renderCases() {
            const container = document.getElementById('cases-container');
            container.innerHTML = '';
            
            casesData.forEach(c => {
                const card = document.createElement('div');
                card.className = `case-card ${c.isBtc ? 'btc-card' : ''}`;
                
                if (c.isBtc) {
                    // Кейс за биткоины
                    card.innerHTML = `
                        <div class="case-image">₿</div>
                        <div class="case-name">${c.name} <span style="color:var(--btn-btc); font-size:12px;">(BTC)</span></div>
                        <div class="case-price-btc">${c.price.toFixed(2)} ₿</div>
                        <button class="btn-open btc-btn" onclick="openCase(${c.id})">Открыть</button>
                    `;
                } else {
                    // Обычный кейс
                    card.innerHTML = `
                        <div class="case-image">📦</div>
                        <div class="case-name">${c.name}</div>
                        <div class="case-price-rub">${c.price.toLocaleString('ru-RU')} ₽</div>
                        <button class="btn-open" onclick="openCase(${c.id})">Открыть</button>
                    `;
                }
                container.appendChild(card);
            });
        }

        // Рендер инвентаря
        function renderInventory() {
            const container = document.getElementById('inventory-container');
            container.innerHTML = '';
            
            if (state.inventory.length === 0) {
                container.innerHTML = '<p style="color:var(--text-muted); grid-column: 1/-1;">Инвентарь пуст. Откройте кейс!</p>';
                return;
            }

            state.inventory.forEach((item, index) => {
                const div = document.createElement('div');
                div.className = 'inv-item';
                div.innerHTML = `
                    <img src="${item.img}" alt="${item.name}">
                    <div class="inv-item-name">${item.name}</div>
                    <div class="inv-item-price">${item.price.toLocaleString('ru-RU')} ₽</div>
                    <button class="btn-sell" onclick="sellItem(${index})">Продать</button>
                    <button class="btn-open" style="margin-top:5px; font-size:12px; padding:5px;" onclick="selectForUpgrade(${index})">В апгрейд</button>
                `;
                container.appendChild(div);
            });
        }

        // --- ЛОГИКА ---
        
        // Открытие кейса
        function openCase(caseId) {
            const currentCase = casesData.find(c => c.id === caseId);
            
            // Проверка баланса
            if (currentCase.isBtc) {
                if (state.bitcoins < currentCase.price) {
                    showNotification("Недостаточно BTC!");
                    return;
                }
                state.bitcoins -= currentCase.price;
                // Округляем до 2 знаков, чтобы не было 0.300000004
                state.bitcoins = parseFloat(state.bitcoins.toFixed(2));
            } else {
                if (state.balance < currentCase.price) {
                    showNotification("Недостаточно средств!");
                    return;
                }
                state.balance -= currentCase.price;
            }

            // Выдаем скин
            const randomIndex = Math.floor(Math.random() * currentCase.items.length);
            const wonItem = currentCase.items[randomIndex];
            state.inventory.push(wonItem);
            
            updateBalanceUI();
            renderInventory();
            saveState();

            // Показываем модалку
            document.getElementById('modal-img').src = wonItem.img;
            document.getElementById('modal-name').innerText = wonItem.name;
            document.getElementById('modal-price').innerText = wonItem.price.toLocaleString('ru-RU') + ' ₽';
            document.getElementById('win-modal').style.display = 'flex';
        }

        // Продажа скина
        function sellItem(index) {
            const item = state.inventory[index];
            state.balance += item.price;
            state.inventory.splice(index, 1);
            
            updateBalanceUI();
            renderInventory();
            saveState();
            showNotification(`Вы продали ${item.name} за ${item.price} ₽`, true);
        }

        // Обменник валют
        function exchangeCurrency(type) {
            const rate = 50000;
            if (type === 'rubToBtc') {
                if (state.balance >= rate) {
                    state.balance -= rate;
                    state.bitcoins += 1;
                    showNotification(`Вы купили 1 ₿ за ${rate} ₽`, true);
                } else {
                    showNotification("Недостаточно рублей!");
                }
            } else if (type === 'btcToRub') {
                if (state.bitcoins >= 1) {
                    state.bitcoins -= 1;
                    state.balance += rate;
                    showNotification(`Вы продали 1 ₿ за ${rate} ₽`, true);
                } else {
                    showNotification("Недостаточно биткоинов!");
                }
            }
            updateBalanceUI();
            saveState();
        }

        // Навигация
        function switchTab(tabName) {
            document.querySelectorAll('.tab-content').forEach(el => el.style.display = 'none');
            document.querySelectorAll('.nav-btn').forEach(el => el.classList.remove('active'));
            
            document.getElementById('tab-' + tabName).style.display = 'block';
            document.querySelector(`.nav-btn[onclick="switchTab('${tabName}')"]`).classList.add('active');
            
            const titles = { cases: "Сериные кейсы", inventory: "Ваш Инвентарь", upgrade: "Апгрейд скинов" };
            document.getElementById('page-title').innerText = titles[tabName];
        }

        // --- АПГРЕЙД ---
        let currentUpgradeItem = null;
        let currentMultiplier = null;
        let currentChance = null;

        function selectForUpgrade(index) {
            currentUpgradeItem = state.inventory[index];
            currentUpgradeItem.invIndex = index;
            
            const slot = document.getElementById('upgrade-slot-from');
            slot.innerHTML = `
                <img src="${currentUpgradeItem.img}">
                <div style="font-size:12px; margin-top:5px;">${currentUpgradeItem.name}</div>
                <div style="color:var(--accent); font-weight:bold;">${currentUpgradeItem.price} ₽</div>
            `;
            
            switchTab('upgrade');
        }

        function setUpgrade(multiplier, chance, btnElement) {
            currentMultiplier = multiplier;
            currentChance = chance;
            
            document.querySelectorAll('.mult-btn').forEach(b => b.classList.remove('active'));
            btnElement.classList.add('active');

            if (currentUpgradeItem) {
                const targetPrice = Math.floor(currentUpgradeItem.price * multiplier);
                const slotTo = document.getElementById('upgrade-slot-to');
                slotTo.innerHTML = `
                    <div style="font-size: 24px; color: var(--accent);">${targetPrice.toLocaleString('ru-RU')} ₽</div>
                    <div style="font-size:12px; color:var(--text-muted); margin-top:5px;">Шанс: ${chance}%</div>
                `;
            }
        }

        function doUpgrade() {
            if (!currentUpgradeItem || !currentMultiplier) {
                showNotification("Выберите скин и множитель!");
                return;
            }

            const roll = Math.random() * 100;

            if (roll <= currentChance) {
                const oldItemName = currentUpgradeItem.name;
                const targetPrice = Math.floor(currentUpgradeItem.price * currentMultiplier);
                
                state.inventory.splice(currentUpgradeItem.invIndex, 1);
                state.balance += targetPrice;
                
                showNotification(`УСПЕХ! Вы получили ${targetPrice} ₽ вместо ${oldItemName}`, true);
            } else {
                state.inventory.splice(currentUpgradeItem.invIndex, 1);
                showNotification(`Провал! Скин ${currentUpgradeItem.name} сгорел.`);
            }

            currentUpgradeItem = null;
            currentMultiplier = null;
            document.getElementById('upgrade-slot-from').innerHTML = '<span style="color:var(--text-muted)">Выберите скин</span>';
            document.getElementById('upgrade-slot-to').innerHTML = '<span style="color:var(--text-muted)">Результат</span>';
            document.querySelectorAll('.mult-btn').forEach(b => b.classList.remove('active'));

            updateBalanceUI();
            renderInventory();
            saveState();
        }

        // --- ВСПОМОГАТЕЛЬНЫЕ ---
        function closeModal() {
            document.getElementById('win-modal').style.display = 'none';
        }

        function showNotification(msg, isSuccess = false) {
            const notif = document.getElementById('notification');
            notif.innerText = msg;
            notif.style.background = isSuccess ? 'var(--btn-green)' : 'var(--btn-red)';
            notif.style.display = 'block';
            setTimeout(() => { notif.style.display = 'none'; }, 3000);
        }

        // --- ИНИЦИАЛИЗАЦИЯ ---
        updateBalanceUI();
        renderCases();
        renderInventory();
    </script>
</body>
</html>