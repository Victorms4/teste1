type SomaProps = {
    num: number;
};

const Soma = (props: SomaProps) => {
    return(
        <>
            <p>{props.num}</p>
        </>
    )
}

export default Soma;