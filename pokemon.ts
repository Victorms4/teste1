export type Pokemon = {
    id: number;
    name: string;
    types:[{
        type: {name: string}
    }];
    weight: number;
    height: number;
    sprites: {
        front_default: string;
    }
    stats:[{
        base_start: number;
        stat: {name: string}
    }]
}