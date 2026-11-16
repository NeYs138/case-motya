<!DOCTYPE html>
<html lang="ru">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<title>StarCase — кейсы CS2</title>
<style>
:root{color-scheme:light dark;--bg:#f3f1fb;--sf:#fff;--sf2:#ebe8f7;--tx:#1b1535;--mu:#6a6490;--ac:#7c4dff;--ac2:#0aa5c9;--gold:#b9770e;--bd:#d9d4ee;--ok:#12906a;box-sizing:border-box;padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}
@media (prefers-color-scheme:dark){:root:not([data-theme="light"]){--bg:#0d0b1e;--sf:#171434;--sf2:#201c45;--tx:#ece9ff;--mu:#9a94c8;--ac:#8f6bff;--ac2:#34d6ff;--gold:#ffc857;--bd:#2d2862;--ok:#3ee0a8}}
:root[data-theme="dark"]{--bg:#0d0b1e;--sf:#171434;--sf2:#201c45;--tx:#ece9ff;--mu:#9a94c8;--ac:#8f6bff;--ac2:#34d6ff;--gold:#ffc857;--bd:#2d2862;--ok:#3ee0a8}
*{box-sizing:border-box}
html{scroll-padding-top:env(safe-area-inset-top,0px)}
body{margin:0;background:var(--bg);color:var(--tx);font:16px/1.5 "Exo 2",system-ui,-apple-system,"Segoe UI",sans-serif;min-height:100vh}
button{font:inherit;color:inherit;cursor:pointer}
button:focus-visible,input:focus-visible,a:focus-visible{outline:2px solid var(--ac2);outline-offset:2px}
header{position:sticky;top:env(safe-area-inset-top,0px);z-index:5;display:flex;align-items:center;gap:20px;padding:10px 24px;background:var(--sf);border-bottom:1px solid var(--bd);flex-wrap:wrap}
.logo{font-weight:800;font-size:22px;letter-spacing:.5px;display:flex;gap:8px;align-items:center}
.logo i{font-style:normal;color:var(--gold)}
nav{display:flex;gap:4px;flex:1;flex-wrap:wrap}
nav a{padding:8px 14px;border-radius:10px;color:var(--mu);text-decoration:none;font-weight:600}
nav a.on,nav a:hover{background:var(--sf2);color:var(--tx)}
.right{display:flex;gap:12px;align-items:center}
.bal{display:flex;align-items:center;gap:8px;background:var(--sf2);padding:6px 6px 6px 14px;border-radius:30px;font-weight:700}
.bal b{color:var(--gold)}
.btn{border:0;border-radius:10px;padding:9px 16px;font-weight:700;background:linear-gradient(135deg,var(--ac),var(--ac2));color:#fff}
.btn.sm{padding:5px 12px;border-radius:20px}
.btn.ghost{background:var(--sf2);color:var(--tx)}
.btn:disabled{opacity:.5;cursor:default}
.ava{width:40px;height:40px;border-radius:50%;border:2px solid var(--ac);object-fit:cover;background:var(--sf2)}
.user{display:flex;gap:10px;align-items:center;cursor:pointer;background:none;border:0;padding:0}
main{max-width:1060px;margin:0 auto;padding:28px 20px 60px}
h1{font-size:28px;margin:0 0 4px}
.sub{color:var(--mu);margin:0 0 24px}
.view{display:none}.view.on{display:block}
.card{background:var(--sf);border:1px solid var(--bd);border-radius:16px;padding:20px}
.grid{display:grid;gap:16px;grid-template-columns:repeat(auto-fill,minmax(210px,1fr))}
.slot{border-style:dashed;text-align:center;color:var(--mu);min-height:190px;display:flex;flex-direction:column;align-items:center;justify-content:center;gap:6px}
.slot big{font-size:34px}
.clicker{text-align:center;padding:36px 20px}
.big{width:210px;height:210px;border-radius:50%;border:0;font-size:64px;color:#fff;background:radial-gradient(circle at 35% 30%,var(--ac2),var(--ac) 60%,#3b1d9a);box-shadow:0 0 0 10px var(--sf2),0 12px 40px rgba(124,77,255,.45);transition:transform .08s;user-select:none;-webkit-tap-highlight-color:transparent}
.big:active{transform:scale(.94)}
.hint{color:var(--mu);margin-top:22px}
.fly{position:fixed;pointer-events:none;font-weight:800;color:var(--gold);animation:fly .8s ease-out forwards;z-index:20}
@keyframes fly{to{transform:translateY(-70px);opacity:0}}
@media (prefers-reduced-motion:reduce){.fly{animation:none;opacity:0}.big{transition:none}}
.task{display:flex;align-items:center;gap:16px;margin-bottom:12px}
.task .in{flex:1}
.bar{height:8px;background:var(--sf2);border-radius:8px;overflow:hidden;margin-top:8px}
.bar i{display:block;height:100%;background:linear-gradient(90deg,var(--ac),var(--ac2))}
.rw{font-weight:800;color:var(--gold);white-space:nowrap}
.prof{display:grid;gap:16px;grid-template-columns:repeat(auto-fit,minmax(280px,1fr))}
.me{display:flex;gap:16px;align-items:center}
.me .ava{width:84px;height:84px}
.stats{display:grid;grid-template-columns:repeat(3,1fr);gap:10px;text-align:center}
.stats b{display:block;font-size:24px;color:var(--ac2)}
.stats span{color:var(--mu);font-size:13px}
input{width:100%;padding:10px 12px;border-radius:10px;border:1px solid var(--bd);background:var(--sf2);color:var(--tx);font:inherit}
.row{display:flex;gap:8px;margin-top:10px}
h3{margin:0 0 10px;font-size:17px}
.empty{color:var(--mu);text-align:center;padding:30px}
.modal{position:fixed;inset:0;background:rgba(5,3,20,.7);display:none;align-items:center;justify-content:center;z-index:30;padding:16px}
.modal.on{display:flex}
.modal .card{width:100%;max-width:400px}
.packs{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin:14px 0}
.pack{background:var(--sf2);border:1px solid var(--bd);border-radius:12px;padding:12px;text-align:center}
.pack:hover{border-color:var(--ac)}
.pack b{display:block;color:var(--gold);font-size:18px}
.toast{position:fixed;left:50%;bottom:calc(24px + env(safe-area-inset-bottom,0px));transform:translateX(-50%);background:var(--sf);border:1px solid var(--ac);padding:10px 18px;border-radius:12px;z-index:40;display:none}
.note{font-size:13px;color:var(--mu);margin-top:10px}
</style>
</head>
<body>
<header>
  <div class="logo"><i>✦</i> StarCase</div>
  <nav id="nav">
    <a href="#cases" data-v="cases">Кейсы</a>
    <a href="#click" data-v="click">Кликер</a>
    <a href="#tasks" data-v="tasks">Задания</a>
    <a href="#profile" data-v="profile">Профиль</a>
  </nav>
  <div class="right">
    <div class="bal" title="Баланс StarCoin"><span>✦ <b id="balTop">0</b> SC</span><button class="btn sm" id="topup">Пополнить</button></div>
    <button class="btn" id="login">Войти через Steam</button>
    <button class="user" id="userBox" style="display:none" aria-label="Профиль"><img class="ava" id="avaTop" alt=""><span id="nameTop"></span></button>
  </div>
</header>

<main>
  <section class="view" id="v-cases">
    <h1>Кейсы</h1>
    <p class="sub">Здесь появятся кейсы CS2. Блок подготовлен для вашего друга.</p>
    <div class="grid" id="caseGrid"></div>
  </section>

  <section class="view" id="v-click">
    <h1>Кликер</h1>
    <p class="sub">Каждый клик добавляет +1 StarCoin на баланс.</p>
    <div class="card clicker">
      <button class="big" id="bigBtn" aria-label="Клик +1">✦</button>
      <div class="hint">Кликов всего: <b id="clicks">0</b></div>
    </div>
  </section>

  <section class="view" id="v-tasks">
    <h1>Ежедневные задания</h1>
    <p class="sub">Обновляются каждый день в 00:00. Награда зачисляется после нажатия «Забрать».</p>
    <div id="taskList"></div>
  </section>

  <section class="view" id="v-profile">
    <h1>Профиль</h1>
    <p class="sub">&nbsp;</p>
    <div class="prof">
      <div class="card">
        <div class="me"><img class="ava" id="avaP" alt=""><div><div style="font-size:20px;font-weight:800" id="nameP">Гость</div><div>Баланс: <b style="color:var(--gold)">✦ <span id="balP">0</span> SC</b></div></div></div>
        <div class="row"><button class="btn" id="topup2">Пополнить</button><button class="btn ghost" id="logout">Выйти</button></div>
      </div>
      <div class="card"><h3>Статистика</h3>
        <div class="stats"><div><b id="stClicks">0</b><span>кликов</span></div><div><b id="stTasks">0</b><span>заданий</span></div><div><b id="stCases">0</b><span>кейсов</span></div></div>
      </div>
      <div class="card"><h3>Trade URL</h3>
        <input id="trade" placeholder="https://steamcommunity.com/tradeoffer/new/?partner=…">
        <div class="row"><button class="btn" id="saveTrade">Сохранить</button></div>
      </div>
      <div class="card"><h3>Промокод</h3>
        <input id="promo" placeholder="Введите код">
        <div class="row"><button class="btn" id="applyPromo">Применить</button></div>
        <div class="note">Пробный код: STAR-50</div>
      </div>
    </div>
    <h3 style="margin-top:28px">Ваши предметы</h3>
    <div class="card empty">Предметов пока нет. Они появятся здесь после открытия кейсов.</div>
  </section>
</main>

<div class="modal" id="mTop"><div class="card">
  <h3>Пополнение баланса</h3>
  <p class="note" style="margin-top:0">Выберите пакет StarCoin. Сейчас это демо: оплата не подключена, монеты зачисляются сразу.</p>
  <div class="packs" id="packs"></div>
  <button class="btn ghost" data-close>Закрыть</button>
</div></div>

<div class="modal" id="mLogin"><div class="card">
  <h3>Вход через Steam</h3>
  <p class="note" style="margin-top:0">Демо-вход. Настоящий вход Steam OpenID подключается на сервере, пока введите ник для проверки.</p>
  <input id="nick" placeholder="Ваш ник" maxlength="20">
  <div class="row"><button class="btn" id="doLogin">Войти</button><button class="btn ghost" data-close>Отмена</button></div>
</div></div>

<div class="toast" id="toast"></div>

<script>
var KEY="starcase_v1",S={user:null,bal:0,clicks:0,tasksDone:0,cases:0,trade:"",day:"",prog:{},claimed:{},promo:false};
try{var raw=localStorage.getItem(KEY);if(raw)S=Object.assign(S,JSON.parse(raw));}catch(e){}
function save(){try{localStorage.setItem(KEY,JSON.stringify(S));}catch(e){}}
function $(i){return document.getElementById(i)}
var TASKS=[
 {id:"login",t:"Заходи каждый день",d:"Зайдите на сайт",goal:1,rw:5},
 {id:"c50",t:"Разминка кликера",d:"Сделайте 50 кликов",goal:50,rw:10},
 {id:"c300",t:"Звёздный марафон",d:"Сделайте 300 кликов",goal:300,rw:40},
 {id:"c1000",t:"Мастер клика",d:"Сделайте 1000 кликов",goal:1000,rw:150}
];
function today(){return new Date().toISOString().slice(0,10)}
function rollDay(){if(S.day!==today()){S.day=today();S.prog={login:1};S.claimed={};save();}}
rollDay();
function avatar(n){var c=(n||"?").charAt(0).toUpperCase();var svg='<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 80 80"><defs><linearGradient id="g" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="#8f6bff"/><stop offset="1" stop-color="#34d6ff"/></linearGradient></defs><rect width="80" height="80" fill="url(#g)"/><text x="40" y="53" font-size="38" font-weight="700" text-anchor="middle" fill="#fff" font-family="sans-serif">'+c+'</text></svg>';return"data:image/svg+xml;utf8,"+encodeURIComponent(svg)}
function toast(m){var t=$("toast");t.textContent=m;t.style.display="block";clearTimeout(toast.h);toast.h=setTimeout(function(){t.style.display="none"},2200)}
function fmt(n){return String(n).replace(/\B(?=(\d{3})+(?!\d))/g,"\u00a0")}
function render(){
 $("balTop").textContent=fmt(S.bal);$("balP").textContent=fmt(S.bal);
 $("clicks").textContent=fmt(S.clicks);$("stClicks").textContent=fmt(S.clicks);$("stTasks").textContent=S.tasksDone;$("stCases").textContent=S.cases;
 var u=S.user;$("login").style.display=u?"none":"";$("userBox").style.display=u?"flex":"none";
 var name=u||"Гость",a=avatar(name);$("nameTop").textContent=name;$("avaTop").src=a;$("avaP").src=a;$("nameP").textContent=name;$("logout").style.display=u?"":"none";
 $("trade").value=S.trade;
 renderTasks();
}
function renderTasks(){
 var h="";TASKS.forEach(function(k){
  var p=Math.min(S.prog[k.id]||0,k.goal),done=p>=k.goal,cl=S.claimed[k.id];
  h+='<div class="card task"><div class="in"><b>'+k.t+'</b><div class="note" style="margin:0">'+k.d+' · '+p+'/'+k.goal+'</div><div class="bar"><i style="width:'+(p/k.goal*100)+'%"></i></div></div><div class="rw">+'+k.rw+' SC</div><button class="btn" data-claim="'+k.id+'"'+((!done||cl)?' disabled':'')+'>'+(cl?'Получено':'Забрать')+'</button></div>';
 });$("taskList").innerHTML=h;
}
$("taskList").addEventListener("click",function(e){
 var id=e.target.getAttribute("data-claim");if(!id)return;
 var k=TASKS.filter(function(x){return x.id===id})[0];
 if(S.claimed[id]||(S.prog[id]||0)<k.goal)return;
 S.claimed[id]=1;S.bal+=k.rw;S.tasksDone++;save();render();toast("+"+k.rw+" SC за задание");
});
$("bigBtn").addEventListener("click",function(e){
 rollDay();S.bal+=1;S.clicks++;
 ["c50","c300","c1000"].forEach(function(id){S.prog[id]=(S.prog[id]||0)+1});
 save();
 $("balTop").textContent=fmt(S.bal);$("balP").textContent=fmt(S.bal);$("clicks").textContent=fmt(S.clicks);$("stClicks").textContent=fmt(S.clicks);
 var f=document.createElement("div");f.className="fly";f.textContent="+1";
 var x=e.clientX||innerWidth/2,y=e.clientY||innerHeight/2;f.style.left=(x-8+(Math.random()*40-20))+"px";f.style.top=(y-20)+"px";
 document.body.appendChild(f);setTimeout(function(){f.remove()},800);
});
// cases placeholder
(function(){var h="";for(var i=0;i<8;i++)h+='<div class="card slot"><big>✦</big><b>Место для кейса</b><span>Скоро</span></div>';$("caseGrid").innerHTML=h})();
// top up packs
var PACKS=[[100,"99 ₽"],[500,"449 ₽"],[1000,"849 ₽"],[5000,"3 990 ₽"]];
$("packs").innerHTML=PACKS.map(function(p,i){return'<button class="pack" data-pk="'+i+'"><b>✦ '+fmt(p[0])+'</b>'+p[1]+'</button>'}).join("");
$("packs").addEventListener("click",function(e){var b=e.target.closest("[data-pk]");if(!b)return;var p=PACKS[b.getAttribute("data-pk")];S.bal+=p[0];save();render();$("mTop").classList.remove("on");toast("Зачислено "+fmt(p[0])+" SC")});
function openTop(){$("mTop").classList.add("on")}
$("topup").onclick=openTop;$("topup2").onclick=openTop;
// login
$("login").onclick=function(){$("mLogin").classList.add("on");$("nick").focus()};
$("doLogin").onclick=function(){var n=$("nick").value.trim();if(!n){toast("Введите ник");return}S.user=n;save();render();$("mLogin").classList.remove("on");toast("Добро пожаловать, "+n)};
$("logout").onclick=function(){S.user=null;save();render();location.hash="cases"};
$("userBox").onclick=function(){location.hash="profile"};
document.querySelectorAll("[data-close]").forEach(function(b){b.onclick=function(){b.closest(".modal").classList.remove("on")}});
document.querySelectorAll(".modal").forEach(function(m){m.addEventListener("click",function(e){if(e.target===m)m.classList.remove("on")})});
$("saveTrade").onclick=function(){S.trade=$("trade").value.trim();save();toast("Trade URL сохранён")};
$("applyPromo").onclick=function(){var c=$("promo").value.trim().toUpperCase();if(c==="STAR-50"&&!S.promo){S.promo=true;S.bal+=50;save();render();toast("+50 SC по промокоду")}else toast(S.promo&&c==="STAR-50"?"Код уже использован":"Код не найден")};
// routing
function route(){var v=(location.hash||"#cases").slice(1);if(!$("v-"+v))v="cases";
 document.querySelectorAll(".view").forEach(function(s){s.classList.toggle("on",s.id==="v-"+v)});
 document.querySelectorAll("#nav a").forEach(function(a){a.classList.toggle("on",a.getAttribute("data-v")===v)})}
addEventListener("hashchange",route);route();render();
</script>
</body>
</html>