const originalSend = window.XMLHttpRequest.prototype.send;
window.XMLHttpRequest.prototype.send = function(){
    console.log("Chaos calling", new Date());
    let that = this;
    setTimeout(function() {
        return originalSend.apply(that, [...arguments]);
    }, 1000);
}
