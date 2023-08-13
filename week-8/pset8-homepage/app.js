const btnBuy = document.getElementById('buyNow');

btnBuy.addEventListener('mouseenter', () => {
    btnBuy.style.backgroundColor = 'rgb(73, 37, 23)';
    btnBuy.style.color = 'rgb(250,217,155)';
    btnBuy.style.boxShadow = '1px 2px 10px rgb(216, 175, 134)';
})
btnBuy.addEventListener('mouseleave', () => {
    btnBuy.style.backgroundColor = '';
    btnBuy.style.color = '';
    btnBuy.style.boxShadow = '';
})
