/**
 * @constructor
 * Initialize your data structure here.
 */
var TrieNode = function() {
    this.children = {}
    this.hasWord = false
};

var Trie = function() {
    this.root = TrieNode();
};

/**
 * @param {string} word
 * @return {void}
 * Inserts a word into the trie.
 */
Trie.prototype.insert = function(word) {
    var node = root

    for (var i = 0; i < word.length; i++) {
        var character = word[i]
        if (!node.children[character]) {
            node.children[character] = new TrieNode()
        }
        node = node.children[character]
    }
    node.hasWord = true
};

/**
 * @param {string} word
 * @return {boolean}
 * Returns if the word is in the trie.
 */
Trie.prototype.search = function(word) {
    var node = root

    for (var i = 0; i < word.length; i++) {
        var character = word[i]
        if (!node.children[character]) {
            return false
        }
        node = node.children[character]
    }

    return node.hasWord === true
};

/**
 * @param {string} prefix
 * @return {boolean}
 * Returns if there is any word in the trie
 * that starts with the given prefix.
 */
Trie.prototype.startsWith = function(prefix) {
    var node = root

    for (var i = 0; i < prefix.length; i++) {
        var character = prefix[i]
        if (!node.children[character]) {
            return false
        }
        node = node.children[character]
    }

    return true
};

/**
 * Your Trie object will be instantiated and called as such:
 * var trie = new Trie();
 * trie.insert("somestring");
 * trie.search("key");
 */