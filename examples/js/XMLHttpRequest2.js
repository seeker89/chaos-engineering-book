function applyChaos(obj, methodName, delay){
    const originalMethod = obj.prototype[methodName];
    obj.prototype[methodName] = function(){
        let that = this;
        let args = [...arguments];
        let cb = function() {
            return originalMethod.apply(that, args);
        }
        setTimeout(cb, delay);
    }
}

applyChaos(window.XMLHttpRequest, "send", 1000);