const originalSend = window.XMLHttpRequest.prototype.send;
var counter = 0;
window.XMLHttpRequest.prototype.send = function(){
    counter++;
    if (counter % 2 == 1){
        return originalSend.apply(this, [...arguments]);
    }
    console.log("Unlucky " + counter + "!", new Date());
    this.dispatchEvent(new Event('error'));
}
