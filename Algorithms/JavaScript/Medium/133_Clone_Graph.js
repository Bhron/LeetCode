/**
 * Definition for undirected graph.
 * function UndirectedGraphNode(label) {
 *     this.label = label;
 *     this.neighbors = [];   // Array of UndirectedGraphNode
 * }
 */

/**
 * @param {UndirectedGraphNode} graph
 * @return {UndirectedGraphNode}
 */
var cloneGraph = function(graph) {
    if (graph === null) {
        return null
    }

    var nodes = []
    var nodeMap = new Map()
    clonedGraph = new UndirectedGraphNode(graph.label)
    nodeMap.set(graph, clonedGraph)
    nodes.push(graph)

    // Clone the nodes
    var start = 0
    while (start < nodes.length) {
        var node = nodes[start++]

        for (var i = 0; i < node.neighbors.length; i++) {
            var neighbor = node.neighbors[i]
            if (!nodeMap.has(neighbor)) {
                clonedNode = new UndirectedGraphNode(neighbor.label)
                nodeMap.set(neighbor, clonedNode)
                nodes.push(neighbor)
            }
        }
    }

    // Clone the connections
    for (i = 0; i < nodes.length; i++) {
        node = nodes[i]
        clonedNode = nodeMap.get(node)

        for (var j = 0; j < node.neighbors.length; j++) {
            neighbor = node.neighbors[j]
            clonedNode.neighbors.push(nodeMap.get(neighbor))
        }
    }

    return clonedGraph
};
