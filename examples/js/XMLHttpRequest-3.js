const originalMethod = window.XMLHttpRequest.send;
window.XMLHttpRequest.send = function(){
    let that = this;
    let args = [...arguments];
    let cb = function() {
        return originalMethod.apply(that, args);
    }
    setTimeout(cb, 1000);
}
