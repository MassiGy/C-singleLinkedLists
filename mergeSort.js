let list = [199, 92, 2, 0];

const mergeSort = (arr) => {
    if (arr.length <= 1) {
        return arr;
    }

    let half = arr.length / 2;

    let left = arr.splice(0, half);

    return merge(mergeSort(left), mergeSort(arr));
};

const merge = (firstArr, secondArr) => {
    let arr = [];

    while (firstArr.length || secondArr.length) {
        if (firstArr.length && secondArr.length) {
            if (firstArr[0] < secondArr[0]) {
                arr.push(firstArr.shift());
            } else {
                arr.push(secondArr.shift());
            }
        }
        // case where the one list has more elements then the other.
        else {
            if (firstArr.length) {
                arr.push(firstArr.shift());
            } else {
                arr.push(secondArr.shift());
            }
        }
    }

    return arr;
};

console.log(list);
console.log(mergeSort(list));
