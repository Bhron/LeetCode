/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    if (path === "") {
        return "";
    }

    var pathComponents = path.split("/").filter(function(str) {
        return str !== "";
    });

    if (pathComponents.length === 0) {
        return "/";
    }

    var componentsStack = [], i = 0;
    for (i = 0; i < pathComponents.length; i++) {
        var component = pathComponents[i]
        if (component === ".") {

        } else if (component === "..") {
            if (componentsStack.length > 0) {
                componentsStack.pop();
            }
        } else {
            componentsStack.push(component);
        }
    }

    var simplifiedPath = "";
    if (componentsStack.length === 0) {
        simplifiedPath = "/";
    } else {
        for (i = 0; i < componentsStack.length; i++) {
            simplifiedPath += "/" + componentsStack[i];
        }
    }

    return simplifiedPath;
};
