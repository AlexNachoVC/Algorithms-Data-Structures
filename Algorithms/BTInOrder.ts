function walk(curr: any | null, path: number[]) : number[] {
    if (!curr) {
        return path;
    }   
    // recurse
    // pre

    // recurse
    walk(curr.left, path);  
    path.push(curr.value);
    walk(curr.right, path);

    // post
    return path;
}

export default function in_order_search(head: any) : number[] {
    return walk(head, []);
}