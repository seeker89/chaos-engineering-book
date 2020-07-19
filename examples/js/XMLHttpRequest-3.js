const originalMethod = window.XMLHttpRequest.prototype.send;
window.XMLHttpRequest.prototype.send = function(){
    let that = this;
    let args = [...arguments];
    let cb = function() {
        return originalMethod.apply(that, args);
    }
    setTimeout(cb, 1000);
}
