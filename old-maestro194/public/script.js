function scrollDown() {
  const scrollTo = .3 * window.innerHeight;
  const duration = 200;
  const startY = window.scrollY;
  const difference = scrollTo - startY;
  const startTime = performance.now();

  (function step() {
      const progress = (performance.now() - startTime) / duration;
      const amount = (p => --p * p * p + 1)(progress);
      window.scrollTo({ top: startY + difference * amount });
      if (progress < 1) requestAnimationFrame(step);
  })();
};

(window.setScrollValue = () => document.body.style.setProperty('--scroll', window.scrollY / window.innerHeight))();
document.addEventListener('scroll', setScrollValue);
window.addEventListener('resize', setScrollValue);

(window.setSquareSizeAndGap = () => {
  const bento = document.querySelector('bento-grid');
  const numColumns = getComputedStyle(bento).gridTemplateColumns.split(' ').length;
  const columnGap = parseInt(getComputedStyle(bento).columnGap);
  const squareSize = (bento.offsetWidth - columnGap * (numColumns - 1)) / numColumns;

  bento.style.setProperty('--square-size', `${squareSize}px`);
  bento.style.setProperty('--gap', `${columnGap}px`);
})();
window.addEventListener('resize', setSquareSizeAndGap);