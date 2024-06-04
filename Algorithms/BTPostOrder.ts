function walk(curr: any | null, path: number[]) : number[] {
    if (!curr) {
        return path;
    }   
    // recurse
    // pre

    // recurse
    walk(curr.left, path);  
    walk(curr.right, path);

    // post
    path.push(curr.value);
    return path;
}

export default function post_order_search(head: any) : number[] {
    return walk(head, []);
}