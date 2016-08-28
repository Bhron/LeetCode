var TrieNode = function() {
    this.children = {}
    this.hasWord = false
}

/**
 * @constructor
 */
var WordDictionary = function() {
    this.root = new TrieNode()
};

/**
 * @param {string} word
 * @return {void}
 * Adds a word into the data structure.
 */
WordDictionary.prototype.addWord = function(word) {
    var node = this.root
    
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
 * Returns if the word is in the data structure. A word could
 * contain the dot character '.' to represent any one letter.
 */
WordDictionary.prototype.search = function(word) {
    return this.searchHelper(word, 0, this.root)
};

WordDictionary.prototype.searchHelper = function(word, position, node) {
    if (node === null) {
        return false
    }
    
    if (position === word.length) {
        return node.hasWord === true
    }
    
    var character = word[position]
    if (character === ".") {
        var wordFound = false
        for (var child in node.children) {
            if (this.searchHelper(word, position + 1, node.children[child])) {
                wordFound = true
                break;
            }
        }
        return wordFound
    } else {
        if (!node.children[character]) {
            return false
        }
        return this.searchHelper(word, position + 1, node.children[character])
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * var wordDictionary = new WordDictionary();
 * wordDictionary.addWord("word");
 * wordDictionary.search("pattern");
 */