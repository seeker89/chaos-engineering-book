const original = window.fetch;
window.fetch = function(){
    console.log("Hello chaos");
    return original.apply(this, [...arguments]);
}