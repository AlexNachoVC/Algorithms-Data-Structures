function walk(curr: any | null, path: number[]) : number[] {
    if (!curr) {
        return path;
    }   
    // recurse
    // pre
    path.push(curr.value);

    // recurse
    walk(curr.left, path);
    walk(curr.right, path);

    // post
    return path;
}

export default function pre_order_search(head: any) : number[] {
    return walk(head, [])
}