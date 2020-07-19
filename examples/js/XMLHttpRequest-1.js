const realOpen = window.XMLHttpRequest.prototype.open;
window.XMLHttpRequest.prototype.open = function() {
    let args = [...arguments];
    console.log(...args);
    return realOpen.apply(this, args);
};
