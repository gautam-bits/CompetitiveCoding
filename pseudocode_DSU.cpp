/*
###########################################
UNION BY PATH COMPRESSION PSEUDOCODE
###########################################
*/

/*

-> ID of a set is the root of the tree
parent[N] -> parent of i-th element
rank[N] -> height of subtree with root i

functions - 
1) makeSet
2) union
3) find

//making set O(1)
makeSet(i) -> {
    parent[i] = i;
    rank[i] = 0;
}

// finding parent O(height_tree)  ie O(logn)
find(i) -> {
    while (i != parent[i]) {
        i = parent[i];
    }
    return i;
}

//  merge by hanging shorter one to the bigger one
// if we merge by this greedy approach then height_tree = O(logn)

union(i,j) -> {         //O(logn)
    int i_id = find(i)
    int j_id = find(j)

    if(i_id == j_id) return;

    if(rank[i_id] > rank[j_id]) {
        parent[j_id] = i_id;
    }
    else{
        parent[i_id] = j_id
        if(rank[i_id] == rank[j_id]){
            rank[j_id]++;
        }
    }

}



*/