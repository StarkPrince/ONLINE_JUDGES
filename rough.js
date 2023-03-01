const dlRedGif = require("redgif-dl")

dlRedGif("https://www.redgifs.com/watch/wellgroomedregalredheadedwoodpecker", "anything", "./", true)
    .then((path) =>
    {
        console.log(`The high quality video is located at ${path.HQ}`);
        console.log(`The low quality video is located at ${path.LQ}`);
    })
    .catch((reason) => console.error(reason));
// console.log("something")