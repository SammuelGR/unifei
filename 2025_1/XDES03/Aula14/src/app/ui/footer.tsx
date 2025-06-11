import squirtle from 'public/squirtle.png';
import bulbasaur from 'public/bulbasaur.png';
import charmander from 'public/charmander.png';
import pikachu from 'public/pikachu.jpg';
import mew from 'public/mew.jpg';
import Image from 'next/image';

import "@/app/styles/footer.css";
export default function Footer(){
    return(
        <footer className='footer'>
            <section className='footer-images'>
                <Image className='img-footer' src={bulbasaur} alt='O bulbasaur'/>
                <Image className='img-footer' src={charmander} alt='O charmander'/>
                <Image className='img-footer' src={squirtle} alt='O squirtle'/>
                <Image className='img-footer' src={pikachu} alt='O pikachu'/>
                <Image className='img-footer' src={mew} alt='O mew'/>
            </section>
            <section>
                <p style={{textAlign: "center"}}>Feito com 🎮 por <a href="https://www.github.com/phillima" target='_blank'>philcisco</a></p>
            </section>
        </footer>
    );
}